#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta carta) {
    return carta.populacao / carta.area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

void compararCartas(Carta carta1, Carta carta2, char atributo) {
    printf("Comparação de cartas (Atributo: %c):\n", atributo);
    
    // Comparação de atributos
    if (atributo == 'P') {  // Atributo: População
        printf("Carta 1 - %s: %d\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 - %s: %d\n", carta2.nomeCidade, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (atributo == 'A') {  // Atributo: Área
        printf("Carta 1 - %s: %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("Carta 2 - %s: %.2f km²\n", carta2.nomeCidade, carta2.area);

        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (atributo == 'I') {  // Atributo: PIB
        printf("Carta 1 - %s: %.2f bilhões de reais\n", carta1.nomeCidade, carta1.pib);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", carta2.nomeCidade, carta2.pib);

        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (carta1.pib < carta2.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (atributo == 'D') {  // Atributo: Densidade Populacional
        float densidade1 = calcularDensidadePopulacional(carta1);
        float densidade2 = calcularDensidadePopulacional(carta2);

        printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nomeCidade, densidade1);
        printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nomeCidade, densidade2);

        if (densidade1 < densidade2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (densidade1 > densidade2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }

    } else if (atributo == 'B') {  // Atributo: PIB per capita
        float pibPerCapita1 = calcularPibPerCapita(carta1);
        float pibPerCapita2 = calcularPibPerCapita(carta2);

        printf("Carta 1 - %s: %.2f reais\n", carta1.nomeCidade, pibPerCapita1);
        printf("Carta 2 - %s: %.2f reais\n", carta2.nomeCidade, pibPerCapita2);

        if (pibPerCapita1 > pibPerCapita2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (pibPerCapita1 < pibPerCapita2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Cartas para comparação
    Carta carta1 = {"SP", "A01", "São Paulo", 12325000, 1521.11, 699.28, 50};
    Carta carta2 = {"RJ", "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};

    // Calcular e exibir Densidade Populacional e PIB per capita para cada carta
    float densidade1 = calcularDensidadePopulacional(carta1);
    float densidade2 = calcularDensidadePopulacional(carta2);
    printf("Densidade Populacional - Carta 1: %.2f hab/km², Carta 2: %.2f hab/km²\n", densidade1, densidade2);

    float pibPerCapita1 = calcularPibPerCapita(carta1);
    float pibPerCapita2 = calcularPibPerCapita(carta2);
    printf("PIB per Capita - Carta 1: %.2f reais, Carta 2: %.2f reais\n", pibPerCapita1, pibPerCapita2);

    // Comparação entre as cartas com base no atributo escolhido
    char atributo = 'P'; // 'P' para População, 'A' para Área, 'I' para PIB, 'D' para Densidade, 'B' para PIB per Capita
    compararCartas(carta1, carta2, atributo);

    return 0;
}
