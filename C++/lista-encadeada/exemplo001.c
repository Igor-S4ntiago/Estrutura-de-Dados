
#include <stdio.h>
#include <stdlib.h>

typedef struct Item{

    int chave; 
    struct Item * Proximo; // Ponteiro
    
} Item; // Definindo a estrutura de cada item

int main () {
    system("cls");

    //Exemplo de uso: declarando um item

    Item * A = (Item *) malloc (sizeof(Item));

    if (A==NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        exit(1);
    }

    A-> chave = 25;
    A-> Proximo = NULL;

    printf("Endereço de memória do A: %X\n", A); // %X (em hexadecimal)
    printf("Chave: %d\n", A->chave);

    Item * B = (Item *)malloc(sizeof(Item));

    if (B==NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        exit(1);
    }

    B->chave = 36;
    B->Proximo = NULL;

    printf("Endereço de memória do B: %X\n", B); // %X mostra o hexadecimal correspondente
    printf("Chave: %d\n\n", B->chave);

    Item * C = (Item *)malloc(sizeof(Item));

    if (C==NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        exit(1);
    }

    C->chave = 40;
    C->Proximo = NULL;

    printf("Endereço de memória do C: %X\n", C); // %X mostra o hexadecimal correspondente
    printf("Chave: %d \n\n", C->chave);

    Item * D = (Item *)malloc(sizeof(Item));

    if (D==NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        exit(1);
    }

    D->chave = 10;
    D->Proximo = NULL;

    printf("Endereço de memória do D: %X\n", D); // %X mostra o hexadecimal correspondente
    printf("Chave: %d\n", D->chave);
    printf("\n");


    return 0 ;
}
    Item * CriarItem(int chave) {
    Item * X = (Item *) malloc(sizeof(Item));
    X->chave = chave;
    X->Proximo = NULL;
    return X;
}
