#include <stdio.h>

int main() {
    int height;

    // Solicitar ao usuário que digite a altura
    do {
        printf("Qual será a altura da sua Pirâmide? (entre 1 e 8): ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    // Imprimir a pirâmide com a altura especificada pelo usuário
    printf("Sua pirâmide possui altura %d:\n", height);
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
