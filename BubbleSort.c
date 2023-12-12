#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int vetor[] = {144, 45, 1026, 178, 0, 145, 10, 16};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    bubbleSort(vetor, tamanho);

    printf("Bubble Sort: ");
    for (int i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    return 0;
}
