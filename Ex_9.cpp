#include <stdio.h>
#include <stdlib.h>

// Função para imprimir a matriz
void imprimiMatriz(int **m, int lis, int cols) {
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int lis, cols;

    // Entrada do tamanho da matriz
    printf("Digite o número de linhas: ");
    scanf("%d", &lis);
    printf("Digite o número de colunas: ");
    scanf("%d", &cols);

    // Alocação dinâmica da matriz
    int **m = (int **)malloc(lis * sizeof(int *));
    if (m == NULL) {
        perror("Erro ao alocar memória para as linhas");
        return 1;
    }

    for (int i = 0; i < lins; i++) {
        m[i] = (int *)malloc(cols * sizeof(int));
        if (m[i] == NULL) {
            perror("Erro ao alocar memória para as colunas");
            for (int j = 0; j < i; j++) {
                free(m[j]);
            }
            free(m);
            return 1;
        }
    }

    // Entrada dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Impressão da matriz
    printf("\nMatriz:\n");
    imprimirMatriz(m, lis, cols);

    // Liberação da memória
    for (int i = 0; i < lis; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
