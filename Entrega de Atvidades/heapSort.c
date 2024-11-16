#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Criar um heap máximo
void heap(int array[], int tamanho, int i) {
    int maior = i;        // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; // Filho esquerdo
    int direita = 2 * i + 2;  // Filho direito

    // Se o filho esquerdo for maior que a raiz
    if (esquerda < tamanho && array[esquerda] > array[maior]) {
        maior = esquerda;
    }

    // Se o filho direito for maior que o maior atual
    if (direita < tamanho && array[direita] > array[maior]) {
        maior = direita;
    }

    // Se o maior não for a raiz
    if (maior != i) {
        int temp = array[i];
        array[i] = array[maior];
        array[maior] = temp;

        // Ajusta o heap
        heap(array, tamanho, maior);
    }
}

// Heap Sort
void heapSort(int array[], int tamanho) {
    // Constrói o heap máximo
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        heap(array, tamanho, i);
    }

    // Extrai os elementos do heap
    for (int i = tamanho - 1; i >= 0; i--) {
        // Move a raiz atual para o final
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Chama heap na árvore reduzida
        heap(array, i, 0);
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

    heapSort(array, SIZE);

    printf("\nArray ordenado com Heap Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
