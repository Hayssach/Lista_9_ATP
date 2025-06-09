#include <stdio.h>
#include <stdlib.h>

// Função para alocar matriz dinamicamente
int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
    }
    return matriz;
}

// Função para preencher a matriz com entrada do usuário
void preencherMatriz(int** matriz, int linhas, int colunas) {
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada
void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função que realiza a multiplicação de duas matrizes
int** multiplicarMatrizes(int** A, int linhasA, int colunasA, int** B, int linhasB, int colunasB) {
    if (colunasA != linhasB) {
        printf("Erro: o número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        return NULL;
    }

    int** resultado = alocarMatriz(linhasA, colunasB);

    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}

int main() {
    int linhasA, colunasA, linhasB, colunasB;

    // Entrada da primeira matriz
    printf("Matriz A:\n");
    printf("Número de linhas: ");
    scanf("%d", &linhasA);
    printf("Número de colunas: ");
    scanf("%d", &colunasA);

    int** A = alocarMatriz(linhasA, colunasA);
    preencherMatriz(A, linhasA, colunasA);

    // Entrada da segunda matriz
    printf("\nMatriz B:\n");
    printf("Número de linhas: ");
    scanf("%d", &linhasB);
    printf("Número de colunas: ");
    scanf("%d", &colunasB);

    int** B = alocarMatriz(linhasB, colunasB);
    preencherMatriz(B, linhasB, colunasB);

    // Verifica e realiza multiplicação
    if (colunasA != linhasB) {
        printf("\nNão é possível realizar o produto matricial. Colunas de A != Linhas de B.\n");
    } else {
        int** C = multiplicarMatrizes(A, linhasA, colunasA, B, linhasB, colunasB);
        printf("\nResultado do produto (A x B):\n");
        imprimirMatriz(C, linhasA, colunasB);
        liberarMatriz(C, linhasA);
    }

    // Libera memória das matrizes A e B
    liberarMatriz(A, linhasA);
    liberarMatriz(B, linhasB);
    getchar();
    return 0;
}
