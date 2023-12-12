#include <stdio.h>

void insertionSort(int vetor[], int tamanho) {
    int i, chave, j;
    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[] = {144, 45, 1026, 178, 0, 145, 10, 16};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    insertionSort(vetor, tamanho);

    printf("Insertion Sort: ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}
