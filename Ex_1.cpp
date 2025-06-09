#include <stdio.h>
#include <stdlib.h>

// Função para alocar uma matriz 3x3
int** aloca_matriz() {
    int** matriz = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int*)malloc(3 * sizeof(int));
    }
    return matriz;
}

// Função para liberar memória de uma matriz 3x3
void libera_matriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função que soma duas matrizes 3x3 e retorna o resultado
int** soma_matrizes(int** A, int** B) {
    int** resultado = aloca_matriz();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    return resultado;
}

// Função para imprimir a matriz 3x3
void imprime_matriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** matriz1 = aloca_matriz();
    int** matriz2 = aloca_matriz();

    // Preenchendo as matrizes com exemplo de dados
    printf("Digite os valores da primeira matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz1[i][j]);

    printf("Digite os valores da segunda matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &matriz2[i][j]);

    int** resultado = soma_matrizes(matriz1, matriz2);

    printf("Resultado da soma das matrizes:\n");
    imprime_matriz(resultado);

    // Liberando memória
    libera_matriz(matriz1);
    libera_matriz(matriz2);
    libera_matriz(resultado);
    
    getchar();
    return 0;
}
