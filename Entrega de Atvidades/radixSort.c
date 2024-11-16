#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

// Encontrar o maior número no array
int encontrarMaximo(int array[], int tamanho) {
    int max = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Ordenar o array por uma posição específica (dígito)
void contar(int array[], int tamanho, int exp) {
    int output[tamanho]; // Array de saída
    int num[10] = {0};

    // Conta a ocorrência de cada dígito no índice `exp`
    for (int i = 0; i < tamanho; i++) {
        num[(array[i] / exp) % 10]++;
    }

    // Atualiza `num` para indicar a posição do dígito no array de saída
    for (int i = 1; i < 10; i++) {
        num[i] += num[i - 1];
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        int digit = (array[i] / exp) % 10;
        output[num[digit] - 1] = array[i];
        num[digit]--;
    }
    for (int i = 0; i < tamanho; i++) {
        array[i] = output[i];
    }
}

// Radix Sort
void radixSort(int array[], int tamanho) {
    // Encontra o maior número para determinar o número de dígitos
    int max = encontrarMaximo(array, tamanho);

    // Ordena cada dígito, começando pela unidade
    for (int exp = 1; max / exp > 0; exp *= 10) {
        contar(array, tamanho, exp);
    }
}

// Array aleatório
void gerarArrayAleatorio(int array[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        array[i] = rand() % 1000;
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

    radixSort(array, SIZE);

    printf("\nArray ordenado com Radix Sort:\n");
    imprimirArray(array, SIZE);

    return 0;
}
