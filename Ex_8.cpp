#include <stdio.h>
#include <stdlib.h>

// Função para alocar a matriz dinamicamente
int** alocaMatriz(int lis, int cols) {
    int** m = (int**)malloc(lis * sizeof(int*));
    if (m == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        exit(1);
    }

    for (int i = 0; i < lis; i++) {
        m[i] = (int*)malloc(cols * sizeof(int));
        if (m[i] == NULL) {
            printf("Erro ao alocar memória para as colunas.\n");
            exit(1);
        }
    }

    return m;
}

// Função para preencher a matriz com entrada do usuário
void preencheMatriz(int** m, int lis, int cols) {
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Função para liberar a memória alocada
void liberaMatriz(int** m, int lis) {
    for (int i = 0; i < lis; i++) {
        free(m[i]); // libera cada linha
    }
    free(m); // libera o vetor de ponteiros
}

int main() {
    int lis, cols;

    printf("Digite o número de linhas: ");
    scanf("%d", &lis);

    printf("Digite o número de colunas: ");
    scanf("%d", &cols);

    // Aloca a matriz
    int**  = alocaMatriz(lis, cols);

    // Preenche a matriz
    preencheMatriz(m, lis, cols);

    // (Opcional) Imprime a matriz preenchida
    printf("\nMatriz preenchida:\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Libera a memória
    liberaMatriz(m, lis);
    getchar();
    
    return 0;
}
