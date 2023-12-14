#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Defina a estrutura do nó da sua tabela hash ou outra estrutura de dados que representará o dicionário

bool load(const char *dictionary)
{
    // Abra o arquivo de dicionário
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }

    // Inicialize sua estrutura de dados para armazenar as palavras do dicionário

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Trate a palavra conforme necessário (por exemplo, converta-a para minúsculas, aloque memória, etc.)

        // Insira a palavra na sua estrutura de dados
    }

    // Feche o arquivo após a leitura
    fclose(file);

    return true;
}

bool check(const char *word) {
    // Implementação da função check
    // Verifica se a palavra está no dicionário
}

unsigned int hash(const char *word) {
    // Implementação da função hash
    // Gere um hash para a palavra
}

unsigned int size(void) {
    // Implementação da função size
    // Retorna o número de palavras no dicionário
}

bool unload(void) {
    // Implementação da função unload
    // Libera a memória alocada pela estrutura de dados
}
