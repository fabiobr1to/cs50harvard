#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Variável para armazenar o valor de troco informado pelo usuário
    float change;

    // Variável para contar o número de moedas
    int coins = 0;

    // Solicita ao usuário o valor do troco até que seja informado um valor válido (não negativo)
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // Converte o valor do troco para centavos, arredondando para o valor mais próximo
    int cents = round(change * 100);

    // Loop para contar o número de moedas de 25 centavos necessárias
    while (cents >= 25)
    {
        coins++;
        cents -= 25;
    }

    // Loop para contar o número de moedas de 10 centavos necessárias
    while (cents >= 10)
    {
        coins++;
        cents -= 10;
    }

    // Loop para contar o número de moedas de 5 centavos necessárias
    while (cents >= 5)
    {
        coins++;
        cents -= 5;
    }

    // Loop para contar o número de moedas de 1 centavo necessárias
    while (cents >= 1)
    {
        coins++;
        cents -= 1;
    }

    // Imprime o resultado final, ou seja, o número total de moedas necessárias para o troco
    printf("%d\n", coins);
}
