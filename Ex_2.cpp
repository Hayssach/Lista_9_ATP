#include <stdio.h>
#include <stdlib.h>

// Função que calcula a transposta
void MT3x3(int** m, int** trans) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[j][i] = m[i][j];
        }
    }
}

// Função auxiliar para imiprimir 
void imprimeMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Função para alocar uma matriz
int** alocarMatriz() {
    int** n = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        n[i] = (int*)malloc(3 * sizeof(int));
    }
    return n;
}

// Função para liberar uma matriz 
void liberarMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int** m = alocarMatriz();
    int** trans = alocarMatriz();

    printf("Digite os 9 elementos da matriz 3x3:\n");
    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            printf("Elemento [%d][%d]: ", k, l);
            scanf("%d", &m[k][l]);
        }
    }

    MT3x3(m, trans);

    printf("\nMatriz original:\n");
    imprimeMatriz(m);

    printf("\nMatriz transposta:\n");
    imprimeMatriz(trans);

    // Liberação da memória
    liberarMatriz(m);
    liberarMatriz(trans);
    
    getchar();
    return 0;
}
