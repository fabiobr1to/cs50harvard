#include <stdio.h>
#include <cs50.h>
#include <math.h> // Incluir o cabeçalho math.h para a função round

int main(void) {
    float troco;
    int num_moedas = 0;

    // Solicitar ao usuário o valor do troco em dólares
    printf("Digite o valor do troco em dólares: ");
    scanf("%f", &troco);

    // Converter o valor do troco para centavos e arredondar para o valor mais próximo
    int troco_centavos = round(troco * 100);

    // Calcular o número de moedas usando o algoritmo ganancioso
    int quarters = troco_centavos / 25;
    troco_centavos %= 25; // Atualizar o valor do troco para o que resta após usar quarters
    int dimes = troco_centavos / 10;
    troco_centavos %= 10; // Atualizar o valor do troco para o que resta após usar dimes
    int nickels = troco_centavos / 5;
    troco_centavos %= 5; // Atualizar o valor do troco para o que resta após usar nickels
    int pennies = troco_centavos; // O que sobrar são os pennies

    // Somar o número de moedas de cada tipo
    num_moedas = quarters + dimes + nickels + pennies;

    // Imprimir o número de moedas na tela
    printf("O menor número de moedas necessário é: %d\n", num_moedas);

    return 0;
}
