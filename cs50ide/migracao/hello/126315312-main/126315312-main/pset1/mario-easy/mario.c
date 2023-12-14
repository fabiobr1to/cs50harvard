#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Solicitar ao usuário que digite a altura da pirâmide
    int height;
    do
    {
        height = get_int("Digite a altura da pirâmide (entre 1 e 8): ");
    }
    while (height < 1 || height > 8);

    // Construir a pirâmide
    for (int i = 1; i <= height; i++)
    {
        // Imprimir espaços em branco para alinhar à direita
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Imprimir hashes para construir a pirâmide
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Imprimir nova linha para finalizar a linha da pirâmide
        printf("\n");
    }

    return 0;
}


