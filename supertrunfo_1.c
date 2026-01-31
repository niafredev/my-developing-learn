#include <stdio.h>

int main() {
    // Ajuste de tipos: unsigned long int para populações grandes
    char estado1[25], codigo1[5], cidade1[50];
    unsigned long int populacao1; 
    float area1, PIB1, densidade1, PIBpercapita1, superPoder1;
    int pontos1;

    char estado2[25], codigo2[5], cidade2[50];
    unsigned long int populacao2; 
    float area2, PIB2, densidade2, PIBpercapita2, superPoder2;
    int pontos2;

    // --- ENTRADA DE DADOS (CARTA 1) ---
    printf("BEM VINDO, insira dados da carta 1\n");
    printf("Digite o estado (ex: A): "); scanf("%s", estado1);
    printf("Digite o codigo (ex: A01): "); scanf("%s", codigo1);
    printf("Digite a cidade: "); scanf("%s", cidade1);
    printf("Digite a população: "); scanf("%lu", &populacao1); // %lu para unsigned long
    printf("Digite a area: "); scanf("%f", &area1);
    printf("Digite o PIB: "); scanf("%f", &PIB1);
    printf("Digite pontos turisticos: "); scanf("%d", &pontos1);

    // --- ENTRADA DE DADOS (CARTA 2) ---
    printf("\nAgora os dados da carta 2\n");
    printf("Digite o estado: "); scanf("%s", estado2);
    printf("Digite o codigo: "); scanf("%s", codigo2);
    printf("Digite a cidade: "); scanf("%s", cidade2);
    printf("Digite a população: "); scanf("%lu", &populacao2);
    printf("Digite a area: "); scanf("%f", &area2);
    printf("Digite o PIB: "); scanf("%f", &PIB2);
    printf("Digite pontos turisticos: "); scanf("%d", &pontos2);

    // --- CÁLCULOS ---
    densidade1 = (float)populacao1 / area1;
    PIBpercapita1 = (PIB1 * 1000000000) / (float)populacao1; // Ajustado para PIB em bilhões

    densidade2 = (float)populacao2 / area2;
    PIBpercapita2 = (PIB2 * 1000000000) / (float)populacao2;

    // Super Poder: Soma de todos os atributos (com inverso da densidade)
    superPoder1 = (float)populacao1 + area1 + PIB1 + (float)pontos1 + PIBpercapita1 + (1.0f / densidade1);
    superPoder2 = (float)populacao2 + area2 + PIB2 + (float)pontos2 + PIBpercapita2 + (1.0f / densidade2);

    // --- SAÍDA DE DADOS (CARTA 1) ---
    printf("\n--- DADOS DA CARTA 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f\n", area1);
    printf("PIB: %.2f\n", PIB1);
    printf("Densidade: %.2f\n", densidade1);
    printf("PIB per capita: %.2f\n", PIBpercapita1);
    printf("Pontos Turísticos: %d\n", pontos1);
    printf("Super Poder: %.2f\n", superPoder1);
    // --- SAÍDA DE DADOS (CARTA 2) ---
    printf("\n--- DADOS DA CARTA 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", PIB2);
    printf("Densidade: %.2f\n", densidade2);
    printf("PIB per capita: %.2f\n", PIBpercapita2);
    printf("Pontos Turísticos: %d\n", pontos2);
    printf("Super Poder: %.2f\n", superPoder2);
// Estructura de decisão para comparar o atributo população
    printf("\n--- RESULTADO DA COMPARAÇÃO ---\n");
    printf("Atributo Escolhido: População\n");
// Comparação direta das populações
// if para o primeiro caso
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } 
    // else if para o segundo caso
    else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    } 
    else { 
        // Caso de empate
        printf("Resultado: Empate!\n");
    }
    return 0;
}

//E Lógico &&
//OU Lógico ||
//Não Lógico !
