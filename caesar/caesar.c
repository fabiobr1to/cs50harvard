void caesarCipher(int key, char *text) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = base + (text[i] - base + key) % 26;
        }
    }
}

int main(int argc, char *argv[]) {
    // Verificação dos argumentos

    // Obtenção da chave e verificação

    char text[1000];

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    int length = strlen(text);
    // Remoção da quebra de linha
    if (text[length - 1] == '\n') {
        text[length - 1] = '\0';
        length--;
    }

    // Criptografia usando a cifra de César
    caesarCipher(key, text);

    printf("ciphertext: %s\n", text);

    return 0;
}
