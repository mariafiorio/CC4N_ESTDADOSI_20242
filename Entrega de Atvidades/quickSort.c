#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

int particionar(int array[], int baixo, int alto) {
    int pivo = array[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (array[j] < pivo) {
            i++;
            // Troca
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    // Troca o pivô com o elemento maior encontrado
    int temp = array[i + 1];
    array[i + 1] = array[alto];
    array[alto] = temp;

    return i + 1;
}

// Quick Sort
void quickSort(int array[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(array, baixo, alto);

        // Ordena as duas metades do array
        quickSort(array, baixo, pi - 1);
        quickSort(array, pi + 1, alto);
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

    quickSort(array, 0, SIZE - 1);

    printf("\nArray ordenado com Quick Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
