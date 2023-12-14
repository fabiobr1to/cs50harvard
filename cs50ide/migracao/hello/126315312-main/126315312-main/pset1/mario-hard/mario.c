#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Inicializar a variável de altura com zero
    int altura = 0;

    // Loop do-while para garantir que a altura seja válida
    do
    {
        // Solicitar ao usuário que digite a altura da pirâmide
        printf("Digite a altura da pirâmide (entre 1 e 8): ");
        altura = get_int("");
    }
    while (altura < 1 || altura > 8); // Verificar se a altura é válida

    // Loop for para imprimir a pirâmide
    for (int i = 1; i <= altura; i++)
    {
        // Imprimir espaços em branco à esquerda para alinhar a pirâmide
        for (int j = 0; j < altura - i; j++)
        {
            printf(" ");
        }

        // Imprimir "#" um número de vezes igual ao número da iteração
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Imprimir dois espaços em branco no meio da pirâmide
        printf("  ");

        // Imprimir "#" novamente um número de vezes igual ao número da iteração
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Imprimir uma nova linha para passar para a próxima linha da pirâmide
        printf("\n");
    }

    return 0;
}
