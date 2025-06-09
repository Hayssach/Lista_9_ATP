#include <stdio.h>
#include <stdlib.h>

// Fun��o para alocar a matriz
int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro ao alocar mem�ria para as linhas.\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar mem�ria para as colunas.\n");
            exit(1);
        }
    }

    return matriz;
}

// Fun��o para liberar a matriz
void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros
}

int main() {
    int linhas, colunas;

    printf("Digite o n�mero de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o n�mero de colunas: ");
    scanf("%d", &colunas);

    int** matriz = alocarMatriz(linhas, colunas);

    // Exemplo: preenchendo a matriz com valores
    printf("Preenchendo a matriz...\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i + j; // valor de exemplo
        }
    }

    // Exemplo: imprimindo a matriz
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a mem�ria alocada
    liberarMatriz(matriz, linhas);
    getchar();
    return 0;
}
