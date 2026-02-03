/* Proyecto realizado desde 0 impartido por mi facultad Estacio, primer proyecto totalmente en portugués siendo el español mi lengua nativa, puede contener errores de escritura ya que fue dispensado
el uso de traductor con el objetivo de mantener el foco en el codigo y en la mejoría de mi escritura en portugues*/


#include <stdio.h>

int main() {
    // --- VARIÁVEIS DE DADOS DAS CARTAS ---
    char estado1[25], codigo1[5], cidade1[50];
    unsigned long int populacao1;
    float area1, PIB1, densidade1, PIBpercapita1;
    int pontos1;

    char estado2[25], codigo2[5], cidade2[50];
    unsigned long int populacao2;
    float area2, PIB2, densidade2, PIBpercapita2;
    int pontos2;

    // --- VARIÁVEIS DE LÓGICA DO JOGO ---
    int opcao1, opcao2;
    float valor1_carta1, valor1_carta2; // Guarda o valor do 1º atributo escolhido
    float valor2_carta1, valor2_carta2; // Guarda o valor do 2º atributo escolhido
    float somaCarta1, somaCarta2;       // A soma final
    char *nomeAtributo1, *nomeAtributo2; // Para exibir o nome na tela

    // --- ENTRADA DE DADOS (CARTA 1) ---
    printf("--- CADASTRO CARTA 1 ---\n");
    printf("Estado (A-H): "); scanf("%s", estado1);
    printf("Codigo (ex: A01): "); scanf("%s", codigo1);
    printf("Cidade: "); scanf("%s", cidade1);
    printf("Populacao: "); scanf("%lu", &populacao1);
    printf("Area (km2): "); scanf("%f", &area1);
    printf("PIB (bilhoes): "); scanf("%f", &PIB1);
    printf("Pontos Turisticos: "); scanf("%d", &pontos1);

    // Cálculos Carta 1
    densidade1 = (float)populacao1 / area1;
    PIBpercapita1 = (PIB1 * 1000000000) / (float)populacao1;

    // --- ENTRADA DE DADOS (CARTA 2) ---
    printf("\n--- CADASTRO CARTA 2 ---\n");
    printf("Estado (A-H): "); scanf("%s", estado2);
    printf("Codigo (ex: A02): "); scanf("%s", codigo2);
    printf("Cidade: "); scanf("%s", cidade2);
    printf("Populacao: "); scanf("%lu", &populacao2);
    printf("Area (km2): "); scanf("%f", &area2);
    printf("PIB (bilhoes): "); scanf("%f", &PIB2);
    printf("Pontos Turisticos: "); scanf("%d", &pontos2);

    // Cálculos Carta 2
    densidade2 = (float)populacao2 / area2;
    PIBpercapita2 = (PIB2 * 1000000000) / (float)populacao2;


    // --- MENU 1: ESCOLHA DO PRIMEIRO ATRIBUTO ---
    printf("\n--- ESCOLHA O 1o ATRIBUTO PARA COMPARAR ---\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("Escolha: ");
    scanf("%d", &opcao1);

    // Switch para definir os valores da primeira comparação
    // Usamos 'casting' (float) para garantir que tudo seja somável depois
    switch (opcao1) {
        case 1:
            nomeAtributo1 = "Populacao";
            valor1_carta1 = (float)populacao1;
            valor1_carta2 = (float)populacao2;
            break;
        case 2:
            nomeAtributo1 = "Area";
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3:
            nomeAtributo1 = "PIB";
            valor1_carta1 = PIB1;
            valor1_carta2 = PIB2;
            break;
        case 4:
            nomeAtributo1 = "Pontos Turisticos";
            valor1_carta1 = (float)pontos1;
            valor1_carta2 = (float)pontos2;
            break;
        case 5:
            nomeAtributo1 = "Densidade";
            valor1_carta1 = densidade1;
            valor1_carta2 = densidade2;
            // Invertemos o valor para a soma, pois densidade menor é melhor
            // Mas para seguir o requisito de "soma", usaremos o valor real aqui
            break;
        default:
            printf("Opcao invalida! Usando Populacao como padrao.\n");
            nomeAtributo1 = "Populacao";
            valor1_carta1 = (float)populacao1;
            valor1_carta2 = (float)populacao2;
            opcao1 = 1; // Força opção 1 para evitar erro no menu 2
    }

    // --- MENU 2: ESCOLHA DO SEGUNDO ATRIBUTO (DINÂMICO) ---
    // Note que usamos 'if' para NÃO mostrar a opção já escolhida
    printf("\n--- ESCOLHA O 2o ATRIBUTO ---\n");
    if (opcao1 != 1) printf("1. Populacao\n");
    if (opcao1 != 2) printf("2. Area\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turisticos\n");
    if (opcao1 != 5) printf("5. Densidade Demografica\n");
    printf("Escolha: ");
    scanf("%d", &opcao2);

    // Validação simples: se escolheu o mesmo, dá erro
    if (opcao1 == opcao2) {
        printf("Voce escolheu o mesmo atributo! O jogo nao pode continuar.\n");
        return 1;
    }

    // Switch para definir os valores da segunda comparação
    switch (opcao2) {
        case 1: nomeAtributo2 = "Populacao"; valor2_carta1 = (float)populacao1; valor2_carta2 = (float)populacao2; break;
        case 2: nomeAtributo2 = "Area"; valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: nomeAtributo2 = "PIB"; valor2_carta1 = PIB1; valor2_carta2 = PIB2; break;
        case 4: nomeAtributo2 = "Pontos Turisticos"; valor2_carta1 = (float)pontos1; valor2_carta2 = (float)pontos2; break;
        case 5: nomeAtributo2 = "Densidade"; valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // --- CÁLCULO DA SOMA ---
    somaCarta1 = valor1_carta1 + valor2_carta1;
    somaCarta2 = valor1_carta2 + valor2_carta2;

    // --- EXIBIÇÃO DOS RESULTADOS ---
    printf("\n========== RESULTADO FINAL ==========\n");
    printf("%s vs %s\n", cidade1, cidade2);
    
    // Comparação 1 (Usando Operador Ternário para decidir quem venceu visualmente)
    printf("1. %s: %.2f vs %.2f -> ", nomeAtributo1, valor1_carta1, valor1_carta2);
    if (opcao1 == 5) { // Regra da Densidade (Menor vence)
        printf("%s venceu!\n", (valor1_carta1 < valor1_carta2) ? "Carta 1" : "Carta 2");
    } else { // Regra normal (Maior vence)
        printf("%s venceu!\n", (valor1_carta1 > valor1_carta2) ? "Carta 1" : "Carta 2");
    }

    // Comparação 2
    printf("2. %s: %.2f vs %.2f -> ", nomeAtributo2, valor2_carta1, valor2_carta2);
    if (opcao2 == 5) { // Regra da Densidade
        printf("%s venceu!\n", (valor2_carta1 < valor2_carta2) ? "Carta 1" : "Carta 2");
    } else { // Regra normal
        printf("%s venceu!\n", (valor2_carta1 > valor2_carta2) ? "Carta 1" : "Carta 2");
    }

    // Resultado da Soma
    printf("\nSOMA DOS ATRIBUTOS:\n");
    printf("Carta 1: %.2f\n", somaCarta1);
    printf("Carta 2: %.2f\n", somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("\n*** VENCEDOR GERAL: CARTA 1 (%s) ***\n", cidade1);
    } else if (somaCarta2 > somaCarta1) {
        printf("\n*** VENCEDOR GERAL: CARTA 2 (%s) ***\n", cidade2);
    } else {
        printf("\n*** EMPATE! ***\n");
    }

    return 0;
}


//NIAFREDEV :)
