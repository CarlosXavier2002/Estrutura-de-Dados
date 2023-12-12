#include <stdio.h>

void selectionSort(int vetor[], int tamanho) {
    int i, j, indice;

    for (i = 0; i < tamanho - 1; i++) {
        indice = i;
        for (j = i + 1; j < tamanho; j++)
            if (vetor[j] < vetor[indice])
                indice = j;

        int temp = vetor[indice];
        vetor[indice] = vetor[i];
        vetor[i] = temp;
    }
}

int main() {
    int vetor[] = { 144, 45, 1026, 178, 0, 145, 10, 16};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    selectionSort(vetor, tamanho);

    printf("Seletion Sort: ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}
