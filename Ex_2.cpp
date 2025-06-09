#include <stdio.h>
#include <stdlib.h>

// Função que calcula a transposta de uma matriz 3x3
void transposta3x3(int** matriz, int** transposta) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

// Função auxiliar para imprimir uma matriz 3x3
void imprimirMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para alocar uma matriz 3x3
int** alocaMatriz() {
    int** m = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    return m;
}

// Função para liberar uma matriz 3x3
void liberaMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int** matriz = alocaMatriz();
    int** transposta = alocaMatriz();

    printf("Digite os 9 elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    transposta3x3(matriz, transposta);

    printf("\nMatriz original:\n");
    imprimirMatriz(matriz);

    printf("\nMatriz transposta:\n");
    imprimirMatriz(transposta);

    // Liberação da memória
    liberaMatriz(matriz);
    liberaMatriz(transposta);
    
    getchar();
    return 0;
}
