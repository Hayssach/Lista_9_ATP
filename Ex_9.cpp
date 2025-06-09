#include <stdio.h>
#include <stdlib.h>

// Fun��o para imprimir a matriz
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;

    // Entrada do tamanho da matriz
    printf("Digite o n�mero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o n�mero de colunas: ");
    scanf("%d", &colunas);

    // Aloca��o din�mica da matriz
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        perror("Erro ao alocar mem�ria para as linhas");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            perror("Erro ao alocar mem�ria para as colunas");
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }

    // Entrada dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impress�o da matriz
    printf("\nMatriz:\n");
    imprimirMatriz(matriz, linhas, colunas);

    // Libera��o da mem�ria
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
