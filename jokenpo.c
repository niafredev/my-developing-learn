#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () { 

    int escolhaJogador, escolhaComputadora;
    int continuar = 1;
    
    srand(time(0));

    do {
        printf("\n--- NUEVA RONDA ---\n");
        printf("1. Papel\n");
        printf("2. Piedra\n");
        printf("3. Tijeras\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &escolhaJogador);


        escolhaComputadora = rand() % 3 + 1;


        switch (escolhaJogador){
            case 1: printf("\nSeleccionaste papel\n"); break;
            case 2: printf("\nSeleccionaste piedra\n"); break;
            case 3: printf("\nSeleccionaste tijeras\n"); break;
            default: printf("\nOpcion invalida\n"); break;
        }


        switch (escolhaComputadora){
            case 1: printf("Computador eligio papel\n"); break;
            case 2: printf("Computador eligio piedra\n"); break;
            case 3: printf("Computador eligio tijeras\n"); break;
        }


        if (escolhaComputadora == escolhaJogador) {
            printf(">> ¡Empate!\n");
        } else if ((escolhaComputadora == 1 && escolhaJogador == 2) || // Papel gana a Piedra
                   (escolhaComputadora == 2 && escolhaJogador == 3) || // Piedra gana a Tijeras
                   (escolhaComputadora == 3 && escolhaJogador == 1))   // Tijeras gana a Papel
        {
            printf(">> Computador gana\n");
        } else {
            printf(">> ¡Ganaste tu!\n");
        }

        printf("\n¿Quieres jugar otra vez? (1 para SI / 0 para NO): ");
        scanf("%d", &continuar);

    } while (continuar == 1); 

    printf("\nGracias por jugar. ¡Adios!\n");

    return 0;
}
