#include <stdio.h>
#include <stdlib.h>

typedef struct Caixa {
  int info;  
  struct Caixa *proxima;
} Caixa;

void inicializarPilha(Caixa **pilha) {
  *pilha = NULL;
}

void empilhar(Caixa **pilha, int info) { 
  Caixa *novaCaixa = (Caixa *)malloc(sizeof(Caixa));
  novaCaixa->info = info; 
  novaCaixa->proxima = *pilha;
  *pilha = novaCaixa;
}

Caixa *desempilhar(Caixa **pilha) {
  if (*pilha == NULL) {
    return NULL;
  }

  Caixa *caixa = *pilha;
  *pilha = caixa->proxima;
  caixa->proxima = NULL;

  return caixa;
}

int main() {
  Caixa *pilha;

  inicializarPilha(&pilha);

  empilhar(&pilha, 64);
  empilhar(&pilha, 25);
  empilhar(&pilha, 12);
  empilhar(&pilha, 22);
  empilhar(&pilha, 11);
  empilhar(&pilha, 9);

  Caixa *caixa;
  while ((caixa = desempilhar(&pilha)) != NULL) {
    if (caixa->info > 9) {  
      printf("%d\n", caixa->info);  
    }
    free(caixa);
  }

  return 0;
}