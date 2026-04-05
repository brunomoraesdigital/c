#include <stdio.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define LARGURA 67
#define ALTURA 25

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
    float vx = 1.0, vy = 0.5;

    int rastro[ALTURA][LARGURA];
    int i, j;

    for (i = 0; i < ALTURA; i++)
        for (j = 0; j < LARGURA; j++)
            rastro[i][j] = 0;

    float tempo = 0;

    while (1) {

        // movimento
        x += vx;
        y += vy;

        // colisões
        if (x < 1 || x >= LARGURA - 1) vx = -vx;
        if (y < 1 || y >= ALTURA - 1) vy = -vy;

        // adiciona energia no rastro
        int ix = (int)x;
        int iy = (int)y;

        if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
            rastro[iy][ix] = 8;

        // decaimento do rastro
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {
                if (rastro[i][j] > 0)
                    rastro[i][j]--;
            }
        }

        limpar_tela();

        // brilho pulsante
        float brilho = (sin(tempo) + 1) / 2;

        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {

                if (i == (int)y && j == (int)x) {
                    if (brilho > 0.66) printf("@");
                    else if (brilho > 0.33) printf("O");
                    else printf("o");
                } else {

                    if (rastro[i][j] >= 7) printf("@");
                    else if (rastro[i][j] >= 5) printf("#");
                    else if (rastro[i][j] >= 3) printf("*");
                    else if (rastro[i][j] >= 1) printf(".");
                    else printf(" ");
                }
            }
            printf("\n");
        }

        tempo += 0.2;
        pausar(40);
    }

    return 0;
}