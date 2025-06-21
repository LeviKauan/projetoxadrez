#include <stdio.h>

#define SIZE 8 // tabuleiro de xadrez 8x8

// função para mostrar os movimentos do cavalo
void moverCavalo(int x, int y) {
    printf("Movimentos do Cavalo a partir de (%d, %d):\n", x, y);

    // essas duas listas são os "saltos" do cavalo
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // checa os 8 movimentos possíveis do cavalo
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i]; // nova linha
        int ny = y + dy[i]; // nova coluna

        // só mostra se estiver dentro do tabuleiro
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            printf("(%d, %d)\n", nx, ny);
        }
    }
}

int main() {
    int x = 3, y = 3; // posição inicial
    moverCavalo(x, y);
    return 0;
}
