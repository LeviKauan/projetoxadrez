#include <stdio.h>

#define SIZE 8 // Tamanho do tabuleiro
#define PASSOS_MAX 7 // Número máximo de casas que cada peça pode andar

// ---------- Torre com Recursividade ----------
// Movimenta a torre verticalmente para cima
void moverTorreCima(int x, int y, int passos) {
    if (passos == 0 || x - 1 < 0) return;
    printf("Cima -> (%d, %d)\n", x - 1, y);
    moverTorreCima(x - 1, y, passos - 1);
}

// Movimenta a torre verticalmente para baixo
void moverTorreBaixo(int x, int y, int passos) {
    if (passos == 0 || x + 1 >= SIZE) return;
    printf("Baixo -> (%d, %d)\n", x + 1, y);
    moverTorreBaixo(x + 1, y, passos - 1);
}

// Movimenta a torre horizontalmente para a esquerda
void moverTorreEsquerda(int x, int y, int passos) {
    if (passos == 0 || y - 1 < 0) return;
    printf("Esquerda -> (%d, %d)\n", x, y - 1);
    moverTorreEsquerda(x, y - 1, passos - 1);
}

// Movimenta a torre horizontalmente para a direita
void moverTorreDireita(int x, int y, int passos) {
    if (passos == 0 || y + 1 >= SIZE) return;
    printf("Direita -> (%d, %d)\n", x, y + 1);
    moverTorreDireita(x, y + 1, passos - 1);
}

void moverTorre(int x, int y) {
    printf("\n--- Movimentos da Torre a partir de (%d, %d) ---\n", x, y);
    moverTorreCima(x, y, PASSOS_MAX);
    moverTorreBaixo(x, y, PASSOS_MAX);
    moverTorreEsquerda(x, y, PASSOS_MAX);
    moverTorreDireita(x, y, PASSOS_MAX);
}

// ---------- Bispo com Recursividade + Loops Aninhados ----------

void moverBispoDiagonal(int x, int y, int dx, int dy, int passos) {
    if (passos == 0 || x + dx < 0 || x + dx >= SIZE || y + dy < 0 || y + dy >= SIZE) return;
    printf("Diagonal (%+d, %+d) -> (%d, %d)\n", dx, dy, x + dx, y + dy);
    moverBispoDiagonal(x + dx, y + dy, dx, dy, passos - 1);
}

void moverBispo(int x, int y) {
    printf("\n--- Movimentos do Bispo a partir de (%d, %d) ---\n", x, y);
    
    // Loops aninhados para direção (dx, dy)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            // Só considera diagonais (dx != 0 e dy != 0)
            if (dx != 0 && dy != 0) {
                moverBispoDiagonal(x, y, dx, dy, PASSOS_MAX);
            }
        }
    }
}

// ---------- Rainha com Recursividade (Torre + Bispo) ----------
void moverRainha(int x, int y) {
    printf("\n--- Movimentos da Rainha a partir de (%d, %d) ---\n", x, y);
    moverTorre(x, y);
    moverBispo(x, y);
}

// ---------- Cavalo com Loops Aninhados Complexos ----------
void moverCavalo(int x, int y) {
    printf("\n--- Movimentos do Cavalo (somente para cima e direita) a partir de (%d, %d) ---\n", x, y);

    for (int dx = -2; dx <= 0; dx++) {
        for (int dy = 1; dy <= 2; dy++) {
            // movimento em L: 2 para cima e 1 para direita OU 1 para cima e 2 para direita
            if ((dx == -2 && dy == 1) || (dx == -1 && dy == 2)) {
                int nx = x + dx;
                int ny = y + dy;

                // checa se está dentro do tabuleiro
                if (nx < 0 || ny >= SIZE) {
                    continue; // ignora movimentos inválidos
                }

                printf("Cavalo (L) -> (%d, %d)\n", nx, ny);

                if (nx == 0 || ny == SIZE - 1) {
                    break; // evita sair do tabuleiro em próximas iterações
                }
            }
        }
    }
}

// ---------- Função principal ----------
int main() {
    int x = 3, y = 3; // posição inicial da peça

    moverTorre(x, y);
    moverBispo(x, y);
    moverRainha(x, y);
    moverCavalo(x, y);

    return 0;
}