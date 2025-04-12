#include <stdio.h>
#include <stdlib.h>

// Tamanho do tabuleiro
#define TAM 10

// Símbolos do tabuleiro
#define AGUA '~'
#define NAVIO 'N'
#define TIRO_AGUA 'o'
#define TIRO_NAVIO 'X'

// Função para mostrar o tabuleiro
void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  ");
    for (int i = 0; i < TAM; i++) {
        printf(" %d", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf(" %c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio
void posicionarNavio(char tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, char direcao) {
    for (int i = 0; i < tamanho; i++) {
        if (direcao == 'H') {
            tabuleiro[linha][coluna + i] = NAVIO;
        } else {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para atacar uma posição
int atacar(char tabuleiro[TAM][TAM], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == NAVIO) {
        tabuleiro[linha][coluna] = TIRO_NAVIO;
        printf("🔥 ACERTOU!\n");
        return 1;
    } else if (tabuleiro[linha][coluna] == AGUA) {
        tabuleiro[linha][coluna] = TIRO_AGUA;
        printf("💦 Errou...\n");
    } else {
        printf("❗ Já atirou aqui!\n");
    }
    return 0;
}

// Verifica se ainda há navios no tabuleiro
int verificarVitoria(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == NAVIO) return 0;
        }
    }
    return 1;
}

int main() {
    char jogador[TAM][TAM], inimigo[TAM][TAM];
    int linha, coluna, acertou;
    char direcao;
    char letra;

    inicializarTabuleiro(jogador);
    inicializarTabuleiro(inimigo);

    printf("🚢 BATALHA NAVAL - Posicione seu navio de 4 espaços!\n");
    mostrarTabuleiro(jogador);

    // POSICIONAMENTO DO JOGADOR
    printf("Digite a linha (A-J): ");
    scanf(" %c", &letra);
    linha = letra - 'A';

    printf("Digite a coluna (0-6): ");
    scanf("%d", &coluna);

    printf("Direção (H para horizontal, V para vertical): ");
    scanf(" %c", &direcao);

    posicionarNavio(jogador, linha, coluna, 4, direcao);
    mostrarTabuleiro(jogador);

    // POSICIONAMENTO SIMPLES DO INIMIGO (automático)
    posicionarNavio(inimigo, 1, 1, 4, 'H');

    printf("🧨 ATAQUE AO INIMIGO!\n");

    while (!verificarVitoria(inimigo)) {
        mostrarTabuleiro(inimigo);
        printf("Ataque! Digite a linha (A-J): ");
        scanf(" %c", &letra);
        linha = letra - 'A';

        printf("Digite a coluna (0-9): ");
        scanf("%d", &coluna);

        acertou = atacar(inimigo, linha, coluna);
    }

    printf("🎉 PARABÉNS! VOCÊ VENCEU!\n");
    return 0;
}
