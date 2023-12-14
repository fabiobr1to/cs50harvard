#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[]) {
    // Verifica se o número correto de argumentos foi passado
    if (argc != 2) {
        fprintf(stderr, "Uso: ./recover imagem\n");
        return 1;
    }

    // Abre o arquivo de imagem forense
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Não foi possível abrir %s.\n", argv[1]);
        return 1;
    }

    // Buffer para ler blocos de 512 bytes
    BYTE buffer[BLOCK_SIZE];

    // Contador para nomear os arquivos JPEG recuperados
    int jpeg_count = 0;

    // Ponteiro para o arquivo de saída
    FILE *img = NULL;

    while (fread(buffer, BLOCK_SIZE, 1, file) == 1) {
        // Verifica se encontrou a assinatura de um JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            // Se já há um arquivo JPEG aberto, fecha-o
            if (img != NULL) {
                fclose(img);
            }

            // Cria um novo arquivo JPEG
            char filename[8];
            sprintf(filename, "%03d.jpg", jpeg_count++);
            img = fopen(filename, "w");
            if (img == NULL) {
                fclose(file);
                fprintf(stderr, "Não foi possível criar %s.\n", filename);
                return 1;
            }
        }

        // Escreve o bloco no arquivo JPEG
        if (img != NULL) {
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }

    // Fecha qualquer arquivo restante aberto
    if (img != NULL) {
        fclose(img);
    }

    // Fecha o arquivo de entrada
    fclose(file);

    return 0;
}
