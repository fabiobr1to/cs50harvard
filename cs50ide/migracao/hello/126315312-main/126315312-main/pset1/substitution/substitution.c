#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET 26

bool is_valid_key(string key);
void substitution_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    substitution_cipher(plaintext, key);

    return 0;
}

bool is_valid_key(string key)
{
    int len = strlen(key);
    if (len != ALPHABET)
    {
        return false;
    }

    int freq[ALPHABET];
    memset(freq, 0, sizeof(freq));

    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (freq[index] > 0)
        {
            return false;
        }
        freq[index]++;
    }

    return true;
}

void substitution_cipher(string plaintext, string key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            bool is_upper = isupper(c);
            char shift = is_upper ? 'A' : 'a';
            int index = toupper(c) - 'A';
            char substituted_char = is_upper ? toupper(key[index]) : tolower(key[index]);
            printf("%c", substituted_char);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
