#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fun��o que verifica se um n�mero est� presente na matriz 3x3
bool encontrarNumero(int** matriz, int numero, int *linha, int *coluna) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == numero) {
                *linha = i;
                *coluna = j;
                return true;
            }
        }
    }
    return false;
}

// Fun��o para alocar uma matriz 3x3 dinamicamente
int** alocaMatriz() {
    int** matriz = (int**)malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int*)malloc(3 * sizeof(int));
    }
    return matriz;
}

// Fun��o para liberar a matriz 3x3
void liberaMatriz(int** matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int** matriz = alocaMatriz();

    // Preenchendo com os mesmos valores do seu exemplo
    int valores[3][3] = {
        {4, 7, 1},
        {8, 2, 9},
        {5, 3, 6}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = valores[i][j];

    int numero;
    printf("Digite o n�mero a ser procurado: ");
    scanf("%d", &numero);

    int linha, coluna;

    if (encontrarNumero(matriz, numero, &linha, &coluna)) {
        printf("N�mero %d encontrado na posi��o [%d][%d]\n", numero, linha, coluna);
    } else {
        printf("N�mero %d n�o encontrado na matriz.\n", numero);
    }

    liberaMatriz(matriz); // Libera mem�ria alocada
    
    getchar();
    return 0;
}
