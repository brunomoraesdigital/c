#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define LARGURA 67
#define ALTURA 100

void pausar(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    float x = 10, y = 5;
    float vx = 1.2, vy = 0;

    float gravidade = 0.2;
    float quique = 0.85;

    int rastro[ALTURA][LARGURA];
    int i, j;

    // inicializa rastro
    for (i = 0; i < ALTURA; i++)
        for (j = 0; j < LARGURA; j++)
            rastro[i][j] = 0;

    while (1) {

        // física
        vy += gravidade;

        x += vx;
        y += vy;

        // colisões laterais
        if (x < 0) {
            x = 0;
            vx = -vx;
        }

        if (x >= LARGURA) {
            x = LARGURA - 1;
            vx = -vx;
        }

        // colisão chão
        if (y >= ALTURA - 1) {
            y = ALTURA - 1;
            vy = -vy * quique;
        }

        // adiciona rastro
        int ix = (int)x;
        int iy = (int)y;

        if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
            rastro[iy][ix] = 5;

        // decai rastro
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {
                if (rastro[i][j] > 0)
                    rastro[i][j]--;
            }
        }

        limpar_tela();

        // desenha
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {

                if ((int)x == j && (int)y == i) {
                    printf("O");
                } else {
                    if (rastro[i][j] >= 4) printf("@");
                    else if (rastro[i][j] >= 3) printf("#");
                    else if (rastro[i][j] >= 2) printf("*");
                    else if (rastro[i][j] >= 1) printf(".");
                    else printf(" ");
                }
            }
            printf("\n");
        }

        pausar(40);
    }

    return 0;
}