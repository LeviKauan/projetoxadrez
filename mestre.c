#include <stdio.h>

#define SIZE 8 // tamanho do tabuleiro

// função recursiva para movimentar a rainha numa direção
void moverRainhaRec(int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;

    // se ainda estiver dentro do tabuleiro, continua indo
    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
        printf("(%d, %d)\n", nx, ny);
        moverRainhaRec(nx, ny, dx, dy); // chama de novo (recursão)
    }
}

// essa chama a recursão pra cada direção que a rainha pode ir
void todosMovimentosRainha(int x, int y) {
    printf("Movimentos recursivos da Rainha a partir de (%d, %d):\n", x, y);

    // as 8 direções possíveis
    int direcoes[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    // faz a rainha andar em todas as direções
    for (int i = 0; i < 8; i++) {
        moverRainhaRec(x, y, direcoes[i][0], direcoes[i][1]);
    }
}

// o cavalo com "profundidade", ou seja, ele pode fazer mais de um pulo
void moverCavaloComplexo(int x, int y, int profundidade) {
    if (profundidade == 0) return; // parando a recursão

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // se estiver dentro do tabuleiro, continua
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            printf("Profundidade %d -> (%d, %d)\n", profundidade, nx, ny);
            moverCavaloComplexo(nx, ny, profundidade - 1); // vai pulando mais
        }
    }
}

int main() {
    int x = 3, y = 3;
    todosMovimentosRainha(x, y);
    moverCavaloComplexo(x, y, 2); // pode mudar o "2" pra mais pulos
    return 0;
}
