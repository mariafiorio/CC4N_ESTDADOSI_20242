#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamanho 50

// Insertion Sort
void insertionSort(int array[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int item = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > item) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = item;
    }
}

// gerar um arrayay aleatório
void gerarArrayAleatorio(int array[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100;
    }
}

// imprimir o array
void imprimirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[SIZE];
    gerarArrayAleatorio(array, SIZE);

    printf("array original:\n");
    imprimirArray(array, SIZE);

    insertionSort(array, SIZE);

    printf("\narray ordenado com Insertion Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
