#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó AVL
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int altura;
} Node;

// Função para calcular a altura de um nó
int altura(Node* n) {
    return (n == NULL) ? 0 : n->altura;
}

// Calcula o fator de balanceamento
int balanceamento(Node* n) {
    return (n == NULL) ? 0 : altura(n->left) - altura(n->right);
}

// Cria um novo nó
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = valor;
    novo->left = NULL;
    novo->right = NULL;
    novo->altura = 1;
    return novo;
}

// Rotação simples à direita
Node* rotacaoDireita(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->altura = 1 + (altura(y->left) > altura(y->right) ? altura(y->left) : altura(y->right));
    x->altura = 1 + (altura(x->left) > altura(x->right) ? altura(x->left) : altura(x->right));

    return x;
}

// Rotação simples à esquerda
Node* rotacaoEsquerda(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->altura = 1 + (altura(x->left) > altura(x->right) ? altura(x->left) : altura(x->right));
    y->altura = 1 + (altura(y->left) > altura(y->right) ? altura(y->left) : altura(y->right));

    return y;
}

// Insere um valor na árvore AVL
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL)
        return criarNo(valor);

    if (valor < raiz->data)
        raiz->left = inserir(raiz->left, valor);
    else if (valor > raiz->data)
        raiz->right = inserir(raiz->right, valor);
    else
        return raiz; 

    raiz->altura = 1 + (altura(raiz->left) > altura(raiz->right) ? altura(raiz->left) : altura(raiz->right));

    int balanco = balanceamento(raiz);

    if (balanco > 1 && valor < raiz->left->data)
        return rotacaoDireita(raiz);

    if (balanco < -1 && valor > raiz->right->data)
        return rotacaoEsquerda(raiz);

    if (balanco > 1 && valor > raiz->left->data) {
        raiz->left = rotacaoEsquerda(raiz->left);
        return rotacaoDireita(raiz);
    }

    if (balanco < -1 && valor < raiz->right->data) {
        raiz->right = rotacaoDireita(raiz->right);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void imprimirInOrder(Node* raiz) {
    if (raiz != NULL) {
        imprimirInOrder(raiz->left);
        printf("%d ", raiz->data);
        imprimirInOrder(raiz->right);
    }
}

void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->left);
        liberarArvore(raiz->right);
        free(raiz);
    }
}

int main() {
    Node* raiz = NULL;
    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Árvore AVL ordenada:\n");
    imprimirInOrder(raiz);
    printf("\n");

    liberarArvore(raiz);
    return 0;
}
