#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int dado;
  struct No *proximo;
} No;

typedef struct Fila {
  No *primeiro;
  No *ultimo;
} Fila;

void inicializarFila(Fila *fila) {
  fila->primeiro = NULL;
  fila->ultimo = NULL;
}

void enfileirar(Fila *fila, int numero) {
  No *novoNo = (No *)malloc(sizeof(No));
  novoNo->dado = numero;
  novoNo->proximo = NULL;

  if (fila->ultimo == NULL) {
    fila->primeiro = novoNo;
    fila->ultimo = novoNo;
  } else {
    fila->ultimo->proximo = novoNo;
    fila->ultimo = novoNo;
  }
}

int desenfileirar(Fila *fila) {
  if (fila->primeiro == NULL) {
    return -1;
  }

  int numero = fila->primeiro->dado;
  No *no = fila->primeiro;
  fila->primeiro = fila->primeiro->proximo;
  free(no);

  if (fila->primeiro == NULL) {
    fila->ultimo = NULL;
  }

  return numero;
}

int retirarNumero(Fila *fila, int numero) {
  No *atual = fila->primeiro;
  No *anterior = NULL;

  while (atual != NULL && atual->dado != numero) {
    anterior = atual;
    atual = atual->proximo;
  }

  if (atual == NULL) {
    return 0;
  }

  if (anterior == NULL) {
    fila->primeiro = atual->proximo;
  } else {
    anterior->proximo = atual->proximo;
  }

  free(atual);

  if (fila->primeiro == NULL) {
    fila->ultimo = NULL;
  }

  return 1;
}

int filaVazia(Fila *fila) {
  return fila->primeiro == NULL;
}

void imprimirFila(Fila *fila) {
  No *no = fila->primeiro;
  while (no != NULL) {
    printf("%d\n", no->dado);
    no = no->proximo;
  }
}

int main() {
  Fila fila;

  inicializarFila(&fila);

  enfileirar(&fila, 64);
  enfileirar(&fila, 25);
  enfileirar(&fila, 12);
  enfileirar(&fila, 22);
  enfileirar(&fila, 11);
  enfileirar(&fila, 9);

  printf("Fila Inicial:\n");
  imprimirFila(&fila);

  int numeroARetirar = 9;
  if (retirarNumero(&fila, numeroARetirar)) {
    printf("\nNúmero %d retirado da fila:\n", numeroARetirar);
    imprimirFila(&fila);
  } else {
    printf("\nNúmero %d não encontrado na fila.\n", numeroARetirar);
  }

  return 0;
}