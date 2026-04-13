#include <stdio.h>
#include <stdlib.h>

typedef struct Item {

    int Chave;
    struct Item* Anterior; // Ponteiro para o item anterior da lista
    struct Item * Proximo; // Ponteiro para o próximo item da lista
    
} Item;

int main() {

    Item * A = CriarItem(10);
    Item * B = CriarItem(20);
    Item * C = CriarItem(30);
    Item * D = CriarItem(40);
    Item * E = CriarItem(50);
    Item * F = CriarItem(60);

    // Construir o encadeamento A -> B -> C -> D -> E -> F

    A-> Anterior = NULL;
    A-> Proximo = B;

    B-> Anterior = A;
    B-> Proximo = C;

    C-> Anterior = B;
    C-> Proximo = D;

    D-> Anterior = C;
    D-> Proximo = E;

    E-> Anterior = D;
    E-> Proximo = F;

    F-> Anterior = E;
    F-> Proximo = NULL;

    // E, a partir de D, como acessar o item B?

    Item * Atual= D;
    Atual = Atual-> Anterior;
    Atual = Atual-> Anterior;
    
    printf("%d\n", Atual-> Chave);

    // Outra possibilidade

    Item * Temp = D-> Anterior-> Anterior;

}

    Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc (sizeof(Item));

    if (I == NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        return NULL; // poderia ser exit(1);
    }

    I->Chave = Chave;
    I->Anterior = NULL;
    I->Proximo = NULL;

    return I; // Retornando o endereço de memória

}