#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função que verifica se um número está presente na matriz 
bool encontreNumero(int** m, int num, int *l, int *c) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (m[i][j] == num) {
                *l = i;
                *c = j;
                return true;
            }
        }
    }
    return false;
}

// Função para alocar uma matriz dinamicamente
int** alocafMatriz() {
    int** m = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    return m;
}

// Função para liberar a matriz 
void liberarMatriz(int** m) {
    for (int i = 0; i < 3; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int** M = alocarMatriz();

    // Preenchendo a matriz 
    int valores[3][3] = {
        {4, 7, 1},
        {8, 2, 9},
        {5, 3, 6}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            M[i][j] = valores[i][j];

    int num;
    printf("Digite o número a ser procurado: ");
    scanf("%d", &num);

    int l, c;

    if (encontreNumero(M, num, &l, &c)) {
        printf("Número %d encontrado na posição [%d][%d]\n", num, l, c);
    } else {
        printf("Número %d não encontrado na matriz.\n", num);
    }

    liberarMatriz(M); 
    
    getchar();
    return 0;
}
