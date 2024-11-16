#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Shell Sort
void shellSort(int array[], int tamanho) {
    // Define o intervalo inicial
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        // Realiza a ordenação para cada intervalo
        for (int i = intervalo; i < tamanho; i++) {
            int temp = array[i];
            int j;
            // Move elementos que estão fora de ordem no intervalo atual
            for (j = i; j >= intervalo && array[j - intervalo] > temp; j -= intervalo) {
                array[j] = array[j - intervalo];
            }
            array[j] = temp;
        }
    }
}

// Gerar um array aleatório
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

    printf("Array original:\n");
    imprimirArray(array, SIZE);

    shellSort(array, SIZE);

    printf("\nArray ordenado com Shell Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
