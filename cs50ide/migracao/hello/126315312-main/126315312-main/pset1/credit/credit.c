#include <stdio.h>
#include <cs50.h>

// Função para verificar se um número de cartão é válido
bool isValidCardNumber(long long cardNumber)
{
    int sum = 0;
    bool multiply = false;

    while (cardNumber > 0)
    {
        int digit = cardNumber % 10;
        cardNumber /= 10;

        if (multiply)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit / 10 + digit % 10;
            }
        }

        sum += digit;
        multiply = !multiply;
    }

    return sum % 10 == 0;
}

int main(void)
{
    // Solicitar número de cartão de crédito
    long long cardNumber = get_long("Número: ");

    // Verificar bandeira do cartão
    if (isValidCardNumber(cardNumber))
    {
        // American Express: 15 dígitos, começando com 34 ou 37
        if ((cardNumber >= 340000000000000 && cardNumber < 350000000000000) ||
            (cardNumber >= 370000000000000 && cardNumber < 380000000000000))
        {
            printf("AMEX\n");
        }
        // MasterCard: 16 dígitos, começando com 51, 52, 53, 54 ou 55
        else if (cardNumber >= 5100000000000000 && cardNumber < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        // Visa: 13 ou 16 dígitos, começando com 4
        else if ((cardNumber >= 4000000000000 && cardNumber < 5000000000000) ||
                 (cardNumber >= 4000000000000000 && cardNumber < 5000000000000000))
        {
            printf("VISA\n");
        }
        // Inválido
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
