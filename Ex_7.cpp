#include <stdio.h>
#include <stdlib.h>

// Função para imprimir a matriz
void imprimeMatriz(int **m, int lis, int cols) {
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar memória da matriz
void liberaMatriz(int **m, int lis) {
    for (int i = 0; i < lis; i++) {
        free(m[i]);  // libera cada linha
    }
    free(m);  // libera o vetor de ponteiros
}

int main() {
    int ls, cols;

    // Entrada do tamanho da matriz
    printf("Digite o número de linhas: ");
    scanf("%d", &ls);
    printf("Digite o número de colunas: ");
    scanf("%d", &cols);

    // Alocação dinâmica da matriz
    int **m = (int **)malloc(ls * sizeof(int *));
    if (m == NULL) {
        perror("Erro ao alocar memória para as linhas");
        return 1;
    }

    for (int i = 0; i < ls; i++) {
        m[i] = (int *)malloc(cols * sizeof(int));
        if (m[i] == NULL) {
            perror("Erro ao alocar memória para as colunas");
            // Libera o que já foi alocado antes de sair
            for (int j = 0; j < i; j++) {
                free(m[j]);
            }
            free(m);
            return 1;
        }
    }

    // Entrada dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    // Impressão da matriz
    printf("\nMatriz:\n");
    imprimirMatriz(m, ls, cols);

    // Liberação da memória usando a função
    liberarMatriz(m, ls);
    
    getchar();
    return 0;
}
