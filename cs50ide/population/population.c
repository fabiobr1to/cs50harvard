#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Obter o tamanho populacional inicial
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // Obter o tamanho populacional final
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calcular o número de anos necessários
    int years = 0;
    while (start_size < end_size)
    {
        int births = start_size / 3;
        int deaths = start_size / 4;
        start_size = start_size + births - deaths;
        years++;
    }

    // Imprimir o número de anos necessários
    printf("Years: %i\n", years);

    return 0;
}
