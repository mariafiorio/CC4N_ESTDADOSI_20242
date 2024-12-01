#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da BST
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Cria um novo nó
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

// Insere um valor na BST
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->data)
        raiz->left = inserir(raiz->left, valor);
    else if (valor > raiz->data)
        raiz->right = inserir(raiz->right, valor);

    return raiz;
}

// Realiza uma busca na BST
Node* buscar(Node* raiz, int valor) {
    if (raiz == NULL || raiz->data == valor)
        return raiz;

    if (valor < raiz->data)
        return buscar(raiz->left, valor);
    else
        return buscar(raiz->right, valor);
}

// Imprime a BST em ordem (in-order traversal)
void imprimirInOrder(Node* raiz) {
    if (raiz != NULL) {
        imprimirInOrder(raiz->left);
        printf("%d ", raiz->data);
        imprimirInOrder(raiz->right);
    }
}

// Libera a memória alocada para a árvore
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->left);
        liberarArvore(raiz->right);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    int valores[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    // Inserção de valores na BST
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Árvore em ordem (In-order):\n");
    imprimirInOrder(raiz);
    printf("\n");

    // Busca por um valor
    int busca = 40;
    Node* encontrado = buscar(raiz, busca);
    if (encontrado)
        printf("Valor %d encontrado na árvore.\n", busca);
    else
        printf("Valor %d não encontrado.\n", busca);

    liberarArvore(raiz);
    return 0;
}
