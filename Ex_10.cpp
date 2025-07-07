#include <stdio.h>
#include <stdlib.h>

// Função para alocar matriz dinamicamente
int** alocaMatriz(int lis, int cols) {
    int** m = (int**)malloc(lis * sizeof(int*));
    if (m == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    for (int i = 0; i < lis; i++) {
        m[i] = (int*)malloc(cols * sizeof(int));
        if (m[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
    }
    return m;
}

// Função para preencher a matriz com entrada do usuário
void preencheMatriz(int** m, int lis, int cols) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Função para imprimir a matriz
void imprimiMatriz(int** m, int lis, int cols) {
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada
void liberaMatriz(int** m, int lis) {
    for (int i = 0; i < lis; i++) {
        free(m[i]);
    }
    free(m);
}

// Função que realiza a multiplicação de duas matrizes
int** multiplicaMatrizes(int** A, int lisA, int colsA, int** B, int lisB, int colsB) {
    if (colsA != lisB) {
        printf("Erro: o número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return NULL;
    }

    int** result = alocaMatriz(lisA, colsB);

    for (int i = 0; i < lisA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                resul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    int lisA, colsA, lisB, colsB;

    // Entrada da primeira matriz
    printf("Matriz A:\n");
    printf("Número de linhas: ");
    scanf("%d", &lisA);
    printf("Número de colunas: ");
    scanf("%d", &colsA);

    int** A = alocaMatriz(lisA, colsA);
    preencheMatriz(A, lisA, colsA);

    // Entrada da segunda matriz
    printf("\nMatriz B:\n");
    printf("Número de linhas: ");
    scanf("%d", &lisB);
    printf("Número de colunas: ");
    scanf("%d", &colsB);

    int** B = alocaMatriz(lisB, colsB);
    preencheMatriz(B, lisB, colsB);

    // Verifica e realiza multiplicação
    if (colsA != lisB) {
        printf("\nNão é possível realizar o produto matricial. Colunas de A != Linhas de B.\n");
    } else {
        int** D = multiplicarMatrizes(A, lisA, colsA, B, lisB, colsB);
        printf("\nResultado do produto (A x B):\n");
        imprimiMatriz(D, lisA, colsB);
        liberaMatriz(D, lisA);
    }

    // Libera memória das matrizes A e B
    liberarMatriz(A, lisA);
    liberarMatriz(B, lisB);
    getchar();
    return 0;
}
