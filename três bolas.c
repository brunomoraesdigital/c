#include <stdio.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define LARGURA 67
#define ALTURA 25
#define NUM_BOLAS 3

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
} Bola;

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    Bola bolas[NUM_BOLAS] = {
        {10, 5, 1.2, 0},
        {30, 3, -1.0, 0},
        {50, 8, -0.8, 0}
    };

    float gravidade = 0.2;
    float quique = 0.85;

    int rastro[ALTURA][LARGURA];
    int i, j;

    for (i = 0; i < ALTURA; i++)
        for (j = 0; j < LARGURA; j++)
            rastro[i][j] = 0;

    while (1) {

        // física individual
        for (i = 0; i < NUM_BOLAS; i++) {

            bolas[i].vy += gravidade;

            bolas[i].x += bolas[i].vx;
            bolas[i].y += bolas[i].vy;

            // paredes laterais
            if (bolas[i].x < 0) {
                bolas[i].x = 0;
                bolas[i].vx = -bolas[i].vx;
            }

            if (bolas[i].x >= LARGURA) {
                bolas[i].x = LARGURA - 1;
                bolas[i].vx = -bolas[i].vx;
            }

            // chão
            if (bolas[i].y >= ALTURA - 1) {
                bolas[i].y = ALTURA - 1;
                bolas[i].vy = -bolas[i].vy * quique;
            }
        }

        // colisão entre bolas
        for (i = 0; i < NUM_BOLAS; i++) {
            for (j = i + 1; j < NUM_BOLAS; j++) {

                float dx = bolas[j].x - bolas[i].x;
                float dy = bolas[j].y - bolas[i].y;

                float dist = sqrt(dx*dx + dy*dy);

                if (dist < 1.5 && dist > 0) {

                    // normal
                    float nx = dx / dist;
                    float ny = dy / dist;

                    // troca de velocidade (colisão simples)
                    float p = 2 * (
                        bolas[i].vx * nx + bolas[i].vy * ny -
                        bolas[j].vx * nx - bolas[j].vy * ny
                    ) / 2;

                    bolas[i].vx -= p * nx;
                    bolas[i].vy -= p * ny;

                    bolas[j].vx += p * nx;
                    bolas[j].vy += p * ny;
                }
            }
        }

        // rastro
        for (i = 0; i < NUM_BOLAS; i++) {
            int ix = (int)bolas[i].x;
            int iy = (int)bolas[i].y;

            if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
                rastro[iy][ix] = 5;
        }

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

                int desenhou_bola = 0;

                int k;
                for (k = 0; k < NUM_BOLAS; k++) {
                    if ((int)bolas[k].x == j && (int)bolas[k].y == i) {
                        printf("O");
                        desenhou_bola = 1;
                        break;
                    }
                }

                if (!desenhou_bola) {
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