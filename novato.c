#include <stdio.h>

#define SIZE 8 // tamanho do tabuleiro (8x8)

// função para mostrar os lugares que a torre pode ir
void moverTorre(int x, int y) {
    printf("Movimentos da Torre a partir de (%d, %d):\n", x, y);

    // anda nas linhas (vertical)
    for (int i = 0; i < SIZE; i++) {
        if (i != x) printf("(%d, %d)\n", i, y);
    }

    // anda nas colunas (horizontal)
    for (int i = 0; i < SIZE; i++) {
        if (i != y) printf("(%d, %d)\n", x, i);
    }
}

// função para mostrar os lugares que o bispo pode ir
void moverBispo(int x, int y) {
    printf("Movimentos do Bispo a partir de (%d, %d):\n", x, y);

    int i = 1;

    // primeira diagonal (pra baixo e pra direita)
    while (x+i < SIZE && y+i < SIZE) {
        printf("(%d, %d)\n", x+i, y+i);
        i++;
    }

    i = 1;
    // segunda diagonal (pra cima e pra esquerda)
    while (x-i >= 0 && y-i >= 0) {
        printf("(%d, %d)\n", x-i, y-i);
        i++;
    }

    i = 1;
    // terceira e quarta diagonal com do-while (misturado)
    do {
        if (x+i < SIZE && y-i >= 0) printf("(%d, %d)\n", x+i, y-i);
        if (x-i >= 0 && y+i < SIZE) printf("(%d, %d)\n", x-i, y+i);
        i++;
    } while ((x+i < SIZE && y-i >= 0) || (x-i >= 0 && y+i < SIZE));
}

// a rainha pode andar como torre e bispo
void moverRainha(int x, int y) {
    printf("Movimentos da Rainha a partir de (%d, %d):\n", x, y);
    moverTorre(x, y); // chama a torre
    moverBispo(x, y); // chama o bispo
}

// função principal
int main() {
    int x = 3, y = 3; // posição onde a peça começa
    moverTorre(x, y);
    moverBispo(x, y);
    moverRainha(x, y);
    return 0;
}