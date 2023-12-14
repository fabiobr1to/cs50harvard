#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int contar_letras(string texto);
int contar_palavras(string texto);
int contar_frases(string texto);

int main(void)
{
    string texto = get_string("Texto: ");

    int letras = contar_letras(texto);
    int palavras = contar_palavras(texto);
    int frases = contar_frases(texto);

    // Calcular L e S para o índice Coleman-Liau
    float L = (letras / (float) palavras) * 100;
    float S = (frases / (float) palavras) * 100;

    // Calcular o índice Coleman-Liau
    int indice = round(0.0588 * L - 0.296 * S - 15.8);

    // Imprimir o resultado
    if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", indice);
    }

    return 0;
}

int contar_letras(string texto)
{
    int letras = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isalpha(texto[i]))
        {
            letras++;
        }
    }
    return letras;
}

int contar_palavras(string texto)
{
    int palavras = 1; // Começa com 1 para contar a última palavra
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isspace(texto[i]))
        {
            palavras++;
        }
    }
    return palavras;
}

int contar_frases(string texto)
{
    int frases = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
        {
            frases++;
        }
    }
    return frases;
}
