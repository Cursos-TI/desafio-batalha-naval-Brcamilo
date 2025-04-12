#include <stdio.h>

int main() {
    // Movimento da Torre usando for
    // A Torre move-se 5 casas para a direita (horizontal)
    printf("Movimento da Torre:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    printf("\n"); // Linha em branco para separar os blocos

    // Movimento do Bispo usando while
    // O Bispo move-se 5 casas na diagonal para cima e à direita
    printf("Movimento do Bispo:\n");
    int j = 1;
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    printf("\n"); // Linha em branco para separar os blocos

    // Movimento da Rainha usando do-while
    // A Rainha move-se 8 casas para a esquerda (horizontal)
    printf("Movimento da Rainha:\n");
    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    return 0;
}
