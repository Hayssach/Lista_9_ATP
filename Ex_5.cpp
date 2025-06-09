#include <stdio.h>
#include <stdlib.h>

// Função que realiza o produto vetorial entre dois vetores 3D
void produtoVetorial(int a[3], int b[3], int resultado[3]) {
    resultado[0] = a[1]*b[2] - a[2]*b[1];
    resultado[1] = a[2]*b[0] - a[0]*b[2];
    resultado[2] = a[0]*b[1] - a[1]*b[0];
}

// Função que realiza o produto vetorial linha a linha entre duas matrizes 3x3
void produtoVetorialMatrizes(int** A, int** B, int** resultado) {
    for (int i = 0; i < 3; i++) {
        produtoVetorial(A[i], B[i], resultado[i]);
    }
}

// Função para imprimir uma matriz 3x3
void imprimirMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        printf("[ ");
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("]\n");
    }
}

// Função para alocar dinamicamente uma matriz 3x3
int** alocaMatriz() {
    int** matriz = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int*)malloc(3 * sizeof(int));
    }
    return matriz;
}

// Função para liberar uma matriz 3x3
void liberaMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int** A = alocaMatriz();
    int** B = alocaMatriz();
    int** resultado = alocaMatriz();

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
    produtoVetorialMatrizes(A, B, resultado);

    // Impressão do resultado
    printf("\nProduto vetorial (linha a linha) das matrizes:\n");
    imprimirMatriz(resultado);

    // Liberação da memória
    liberaMatriz(A);
    liberaMatriz(B);
    liberaMatriz(resultado);
    
    getchar();
    return 0;
}
