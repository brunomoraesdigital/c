#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define LARGURA 67
#define ALTURA 25
#define PARTICULAS 80

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

typedef struct {
    float x, y;
    float vx, vy;
    int vida;
} Particula;

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    float x = 5, y = 2;
    float vx = 0.8, vy = 0.3;

    int rastro[ALTURA][LARGURA];
    int i, j;

    Particula p[PARTICULAS];

    for (i = 0; i < ALTURA; i++)
        for (j = 0; j < LARGURA; j++)
            rastro[i][j] = 0;

    for (i = 0; i < PARTICULAS; i++)
        p[i].vida = 0;

    srand(time(NULL));

    int explodiu = 0;

    while (1) {

        // movimento do meteorito
        if (!explodiu) {
            x += vx;
            y += vy;

            vy += 0.05; // gravidade

            int ix = (int)x;
            int iy = (int)y;

            if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
                rastro[iy][ix] = 6;

            // impacto
            if (y >= ALTURA - 2) {
                explodiu = 1;

                for (i = 0; i < PARTICULAS; i++) {
                    p[i].x = x;
                    p[i].y = y;

                    float ang = ((float)rand() / RAND_MAX) * 2 * 3.14159;
                    float vel = ((float)rand() / RAND_MAX) * 2;

                    p[i].vx = cos(ang) * vel;
                    p[i].vy = sin(ang) * vel;
                    p[i].vida = 10 + rand() % 10;
                }
            }
        }

        // atualiza partículas
        for (i = 0; i < PARTICULAS; i++) {
            if (p[i].vida > 0) {
                p[i].x += p[i].vx;
                p[i].y += p[i].vy;

                p[i].vy += 0.05; // gravidade
                p[i].vida--;
            }
        }

        // decaimento rastro
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

                int desenhou = 0;

                // partículas (explosão)
                for (int k = 0; k < PARTICULAS; k++) {
                    if (p[k].vida > 0 &&
                        (int)p[k].x == j &&
                        (int)p[k].y == i) {

                        if (p[k].vida > 10) printf("@");
                        else if (p[k].vida > 5) printf("*");
                        else printf(".");
                        desenhou = 1;
                        break;
                    }
                }

                if (desenhou) continue;

                // meteorito
                if (!explodiu && (int)x == j && (int)y == i) {
                    printf("O");
                }
                // rastro
                else {
                    if (rastro[i][j] >= 5) printf("#");
                    else if (rastro[i][j] >= 3) printf("*");
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