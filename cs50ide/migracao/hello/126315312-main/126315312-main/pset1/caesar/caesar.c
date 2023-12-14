#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ALPHABET 26

void caesar_cipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // Verifica se o número de argumentos é válido
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Verifica se o argumento é um número inteiro
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    caesar_cipher(plaintext, key);

    return 0;
}

void caesar_cipher(string plaintext, int key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            char shift = isupper(plaintext[i]) ? 'A' : 'a';
            int pi = plaintext[i] - shift;
            int ci = (pi + key) % ALPHABET;
            printf("%c", ci + shift);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
