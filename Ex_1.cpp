#include <stdio.h>
#include <stdlib.h>

// Função para alocar uma matriz 3x3
int** alocar_matriz() {
    int** m = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    return m;
}

// Função para liberar memória de uma matriz 3x3
void liberar_matriz(int** m) {
    for (int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

// Função que soma duas matrizes 3x3 e retorna o resultado
int** somar_matrizes(int** J, int** I) {
    int** r = alocar_matriz();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            r[i][j] = J[i][j] + I[i][j];
        }
    }
    return r;
}

// Função para imprimir a matriz 3x3
void imprimir_matriz(int** m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int** m1 = alocar_matriz();
    int** m2 = alocar_matriz();

    // Preenchendo as matrizes com exemplo de dados
    printf("Digite os valores da primeira matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &m1[i][j]);

    printf("Digite os valores da segunda matriz 3x3:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &m2[i][j]);

    int** r = somar_matrizes(m1, m2);

    printf("Resultado da soma das matrizes:\n");
    imprimir_matriz(r);

    // Liberando memória
    liberar_matriz(m1);
    liberar_matriz(m2);
    liberar_matriz(r);
    
    getchar();
    return 0;
}
