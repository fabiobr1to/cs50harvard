#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

int main(int argc, char *argv[]) {
    // Verificar argumentos da linha de comando
    if (argc != 4) {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Abrir arquivos de entrada e saída
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fclose(input);
        printf("Could not create file.\n");
        return 1;
    }

    // Obter o fator de volume
    float factor = atof(argv[3]);

    // Ler e escrever cabeçalho
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Modificar amostras e escrever no arquivo de saída
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input)) {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Fechar os arquivos
    fclose(input);
    fclose(output);

    return 0;
}
