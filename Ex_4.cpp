#include <stdio.h>
#include <stdlib.h>

int somarDiagonalPrincipal(int** m) {
    int s = 0;
    for (int i = 0; i < 3; i++) {
        s += m[i][i]; 
    }
    return s;
}

// Função para alocar dinamicamente uma matriz 
int** alocarMatriz() {
    int** m = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    return m;
}


void liberarMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int** M = alocarMatriz();

    
    printf("Digite os valores da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }

    int s = somarDiagonalPrincipal(M);
    printf("\nSoma da diagonal principal: %d\n", s);

    
    liberarMatriz(M);
    getchar();
    return 0;
}
