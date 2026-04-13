// Implementação de uma lista usando ponteiros

#include <stdio.h>
#include <stdlib.h>

typedef struct Item {

    int Chave;
    struct Item * Proximo; // Ponteiro para o próximo item da lista

} Item;

// Definindo a estrutura da lista encadeada (Célula-cabeça)

typedef struct {

    Item * Inicio; // Ponteiro para o primeiro elemento da lista
    Item * Fim; // Ponteiro para o último elemento da lista
    int Tamanho; // Quantos itens foram inseridos na lista

} Lista; 


Item * CriarItem(int Chave); // Função para criar um item
void ExibirLista(Item * Inicio, int Tamanho);
int contarPares(Item * Inicio);

Lista * criarListaVazia();
void InserirItem(Lista * L, Item * I, int Posicao);




int main() {

    system("cls");

    // Declarando os itens A, B, C e D

    Item * A = CriarItem(25);
    Item * B = CriarItem(36);
    Item * C = CriarItem(40);
    Item * D = CriarItem(10);

    Lista * MinhaLista = criarListaVazia();

    InserirItem(MinhaLista, A, 0);
    InserirItem(MinhaLista, C, 1);
    InserirItem(MinhaLista, B, 2);
    InserirItem(MinhaLista, D, 3);

    ExibirLista(A, 4);

    int NumPares = contarPares(A);
    printf("\nA quantidade de pares presentes na lista é %d.\n", NumPares);

    return 0;

}

Item * CriarItem(int Chave) {

    Item * I = (Item *) malloc (sizeof(Item));

    if (I == NULL) {
        printf("ERRO: não existe memória para o Item!\n");
        return NULL; // poderia ser exit(1);
    }

    I->Chave = Chave;
    I->Proximo = NULL;

    return I; // Retornando o endereço de memória

}

void ExibirLista(Item * Inicio, int Tamanho) {

    printf("\n");

    for (int i = 0; Inicio != NULL; i++) {
        printf("%X \t %d \t %X \n", Inicio, Inicio->Chave, Inicio->Proximo);
        Inicio = Inicio->Proximo;
    }

}

int contarPares(Item * Inicio) {

    int Contador = 0; // Para contar quantidade de pares

    Item * Atual = Inicio;

    while (Atual != NULL) {
        if (Atual->Chave % 2 == 0) Contador++;
        Atual = Atual->Proximo;
    }

    return Contador;

}

Lista * criarListaVazia() {

    Lista * L = (Lista *) malloc (sizeof(Lista));

    if (L == NULL) {
        printf("ERRO: não há memória disponível para a lista!\n");
        return NULL;
    }

    L->Inicio = NULL;
    L->Fim = NULL;
    L->Tamanho = 0;

    return L;

}

void InserirItem(Lista * L, Item * I, int Posicao) {

    if (Posicao < 0 || Posicao > L->Tamanho) {
        printf("ERRO: posicao inválida!\n");
        return ;
    }

    if (Posicao == 0) {
        I->Proximo = L->Inicio;
        L->Inicio = I;
    } 
    else {
        Item * Temp = L->Inicio;
        for (int i = 0; i < Posicao - 1; i++) Temp = Temp -> Proximo;
        I->Proximo = Temp->Proximo;
        Temp->Proximo = I;
    }

    L->Tamanho++;

}