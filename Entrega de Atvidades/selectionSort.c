#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Selection Sort
void selectionSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// Gerar array aleatório
void gerarArrayAleatorio(int array[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 100; 
    }
}

// Imprimir o array
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

    selectionSort(array, SIZE);

    printf("\narray ordenado com Selection Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
