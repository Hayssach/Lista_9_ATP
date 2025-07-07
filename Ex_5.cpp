#include <stdio.h>
#include <stdlib.h>

// Função que realiza o produto vetorial entre dois vetores 3D
void produtoVet(int a[3], int b[3], int resultado[3]) {
    result[0] = a[1]*b[2] - a[2]*b[1];
    result[1] = a[2]*b[0] - a[0]*b[2];
    result[2] = a[0]*b[1] - a[1]*b[0];
}

// Função que realiza o produto vetorial linha a linha entre duas matrizes 3x3
void produtoVMatrizes(int** A, int** B, int** result) {
    for (int i = 0; i < 3; i++) {
        produtoVet(A[i], B[i], resut[i]);
    }
}

// Função para imprimir uma matriz 3x3
void imprimiMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("]\n");
    }
}

// Função para alocar dinamicamente uma matriz 3x3
int** alocarMatriz() {
    int** m = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    return m;
}

// Função para liberar uma matriz 3x3
void liberarMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int** A = alocarMatriz();
    int** B = alocarMatriz();
    int** result = alocarMatriz();

    // Entrada dos valores da matriz A
    printf("Digite os elementos da matriz A (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Entrada dos valores da matriz B
    printf("\nDigite os elementos da matriz B (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Cálculo do produto vetorial linha a linha
    produtoVetMatrizes(A, B, result);

    // Impressão do resultado
    printf("\nProduto vetorial (linha a linha) das matrizes:\n");
    imprimiMatriz(result);

    // Liberação da memória
    liberarMatriz(A);
    liberarMatriz(B);
    liberarMatriz(result);
    
    getchar();
    return 0;
}
