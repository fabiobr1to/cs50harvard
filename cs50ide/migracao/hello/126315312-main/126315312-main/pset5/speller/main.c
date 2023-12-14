#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"

int main(int argc, char *argv[]) {
    // Verifica o número de argumentos
    if (argc != 2) {
        printf("Uso: ./test arquivo_de_texto\n");
        return 1;
    }

    // Carrega o dicionário
    const char *dicionario = "dicionario.txt"; // Substitua pelo seu arquivo de dicionário
    bool carregado = load(dicionario);

    if (!carregado) {
        printf("Erro ao carregar o dicionário.\n");
        return 1;
    }

    // Abre o arquivo para verificar palavras
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Realiza a verificação das palavras no arquivo
    char palavra[LENGTH + 1];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (!check(palavra)) {
            printf("Palavra incorreta: %s\n", palavra);
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Descarrega o dicionário
    bool descarregado = unload();
    if (!descarregado) {
        printf("Erro ao descarregar o dicionário.\n");
        return 1;
    }

    return 0;
}
