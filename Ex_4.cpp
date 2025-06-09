#include <stdio.h>
#include <stdlib.h>

// Função que calcula a soma da diagonal principal de uma matriz 3x3
int somaDiagonalPrincipal(int** matriz) {
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][i]; // Elementos onde linha == coluna
    }
    return soma;
}

// Função para alocar dinamicamente uma matriz 3x3
int** alocaMatriz() {
    int** matriz = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int*)malloc(3 * sizeof(int));
    }
    return matriz;
}

// Função para liberar a memória da matriz 3x3
void liberaMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int** matriz = alocaMatriz();

    // Entrada de dados pelo usuário
    printf("Digite os valores da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = somaDiagonalPrincipal(matriz);
    printf("\nSoma da diagonal principal: %d\n", soma);

    // Libera memória
    liberaMatriz(matriz);
    getchar();
    return 0;
}
