#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Função para mesclar dois sub-arrays
void merge(int array[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Criar arrays temporários
    int esquerdaArray[n1], direitaArray[n2];

    // Copiar dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        esquerdaArray[i] = array[esquerda + i];
    for (int i = 0; i < n2; i++)
        direitaArray[i] = array[meio + 1 + i];

    // Mesclar os sub-arrays de volta no array original
    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (esquerdaArray[i] <= direitaArray[j]) {
            array[k] = esquerdaArray[i];
            i++;
        } else {
            array[k] = direitaArray[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes
    while (i < n1) {
        array[k] = esquerdaArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = direitaArray[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(int array[], int esquerda, int direita) {
    if (esquerda < direita) {
        // Ponto médio
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordenar a primeira e a segunda metade
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio + 1, direita);

        // Mesclar as duas metades
        merge(array, esquerda, meio, direita);
    }
}

// Gerar um array 
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

    mergeSort(array, 0, SIZE - 1); // Chama o mergeSort para ordenar o array

    printf("\nArray ordenado com Merge Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}


