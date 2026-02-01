#include <stdio.h>

int main() {
    // --- VARIÁVEIS ---
    char estado1[25], codigo1[5], cidade1[50];
    unsigned long int populacao1; 
    float area1, PIB1, densidade1, PIBpercapita1, superPoder1;
    int pontos1;

    char estado2[25], codigo2[5], cidade2[50];
    unsigned long int populacao2; 
    float area2, PIB2, densidade2, PIBpercapita2, superPoder2;
    int pontos2;

    int opcao; // Variável para o menu

    // --- ENTRADA DE DADOS (CARTA 1) ---
    printf("BEM VINDO, insira dados da carta 1\n");
    printf("Digite o estado (ex: A): "); scanf("%s", estado1);
    printf("Digite o codigo: "); scanf("%s", codigo1);
    printf("Digite a cidade: "); scanf("%s", cidade1);
    printf("Digite a população: "); scanf("%lu", &populacao1);
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
    PIBpercapita1 = (PIB1 * 1000000000) / (float)populacao1;

    densidade2 = (float)populacao2 / area2;
    PIBpercapita2 = (PIB2 * 1000000000) / (float)populacao2;

    superPoder1 = (float)populacao1 + area1 + PIB1 + (float)pontos1 + PIBpercapita1 + (1.0f / densidade1);
    superPoder2 = (float)populacao2 + area2 + PIB2 + (float)pontos2 + PIBpercapita2 + (1.0f / densidade2);

    // --- MENU INTERATIVO ---
    printf("\n--- ESCOLHA O ATRIBUTO PARA COMPARAÇÃO ---\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("6. Super Poder\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO DA BATALHA ---\n");

    // --- LÓGICA DE COMPARAÇÃO COM SWITCH ---
    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %lu\n%s: %lu\n", cidade1, populacao1, cidade2, populacao2);
            if (populacao1 > populacao2) printf("Vencedor: %s\n", cidade1);
            else if (populacao2 > populacao1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f\n%s: %.2f\n", cidade1, area1, cidade2, area2);
            if (area1 > area2) printf("Vencedor: %s\n", cidade1);
            else if (area2 > area1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f\n%s: %.2f\n", cidade1, PIB1, cidade2, PIB2);
            if (PIB1 > PIB2) printf("Vencedor: %s\n", cidade1);
            else if (PIB2 > PIB1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n%s: %d\n", cidade1, pontos1, cidade2, pontos2);
            if (pontos1 > pontos2) printf("Vencedor: %s\n", cidade1);
            else if (pontos2 > pontos1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 5:
            // Regra especial: Menor valor vence
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f\n%s: %.2f\n", cidade1, densidade1, cidade2, densidade2);
            if (densidade1 < densidade2) printf("Vencedor: %s\n", cidade1);
            else if (densidade2 < densidade1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        case 6:
            printf("Atributo: Super Poder\n");
            printf("%s: %.2f\n%s: %.2f\n", cidade1, superPoder1, cidade2, superPoder2);
            if (superPoder1 > superPoder2) printf("Vencedor: %s\n", cidade1);
            else if (superPoder2 > superPoder1) printf("Vencedor: %s\n", cidade2);
            else printf("Empate!\n");
            break;

        default:
            printf("Opção inválida no menu.\n");
            break;
    }

    return 0;
}
