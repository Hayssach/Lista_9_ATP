#include <stdio.h>
#include <stdlib.h>

// Função para alocar a matriz
int** alocaMatriz(int ls, int cs) {
    int** m = (int**)malloc(ls * sizeof(int*));
    if (m == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        exit(1);
    }

    for (int i = 0; i < ls; i++) {
        m[i] = (int*)malloc(cs * sizeof(int));
        if (m[i] == NULL) {
            printf("Erro ao alocar memória para as colunas.\n");
            exit(1);
        }
    }

    return m;
}

// Função para liberar a matriz
void liberaMatriz(int** m, int ls) {
    for (int i = 0; i < ls; i++) {
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

    int** ma = alocaMatriz(lis, cols);

    // Exemplo: preenchendo a matriz com valores
    printf("Preenchendo a matriz...\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            m[i][j] = i + j; // valor de exemplo
        }
    }

    // Exemplo: imprimindo a matriz
    printf("Matriz:\n");
    for (int i = 0; i < lis; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    liberaMatriz(m, lis);
    getchar();
    return 0;
}
