#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif



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

float limitar(float valor, float max) {
    if (valor > max) return max;
    if (valor < -max) return -max;
    return valor;
}

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    float x = 20, y = 5;
    float vx = 1.2, vy = 0;

    float vx_inicial = 1.2;
    float vy_inicial = -2.5;

    float gravidade = 0.2;
    float quique = 0.85;

    int vida = 10;

    int raquete_largura = 9;
    int raquete_x = LARGURA / 2 - raquete_largura / 2;

    int rastro[ALTURA][LARGURA];
    int i, j;

    for (i = 0; i < ALTURA; i++)
        for (j = 0; j < LARGURA; j++)
            rastro[i][j] = 0;

    while (1) {

        // IA da raquete
        int centro = raquete_x + raquete_largura / 2;

        if (x > centro) raquete_x++;
        else if (x < centro) raquete_x--;

        if (raquete_x < 0) raquete_x = 0;
        if (raquete_x + raquete_largura >= LARGURA)
            raquete_x = LARGURA - raquete_largura;

        // física
        vy += gravidade;

        float prox_x = x + vx;
        float prox_y = y + vy;

        // colisão lateral
        if (prox_x < 0 || prox_x >= LARGURA) {
            vx = -vx;
            prox_x = x + vx;
        }

        // colisão com raquete
        if (vy > 0 && prox_y >= ALTURA - 2) {

            if ((int)prox_x >= raquete_x &&
                (int)prox_x <= raquete_x + raquete_largura) {

                y = ALTURA - 3;

                vy = vy_inicial;

                float impacto = (prox_x - (raquete_x + raquete_largura / 2)) / 4.0;
                vx += impacto;

                vx = limitar(vx, vx_inicial);
                vy = limitar(vy, -vy_inicial);

                vida++; // ganha vida

            } else if (prox_y >= ALTURA - 1) {

                y = ALTURA - 1;
                vy = -vy * quique;

                vida--; // perde vida
            }

        } else {
            x = prox_x;
            y = prox_y;
        }

        // fim de jogo
        if (vida <= 0) {
            limpar_tela();
            printf("\n\n      FIM DE JOGO\n");
            printf("Vida chegou a zero\n");
            break;
        }

        // rastro
        int ix = (int)x;
        int iy = (int)y;

        if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
            rastro[iy][ix] = 5;

        for (i = 0; i < ALTURA; i++)
            for (j = 0; j < LARGURA; j++)
                if (rastro[i][j] > 0)
                    rastro[i][j]--;

        limpar_tela();

        // desenha
        for (i = 0; i < ALTURA; i++) {
            for (j = 0; j < LARGURA; j++) {

                if ((int)x == j && (int)y == i) {
                    printf("O");
                }
                else if (i == ALTURA - 1 &&
                         j >= raquete_x &&
                         j <= raquete_x + raquete_largura) {
                    printf("=");
                }
                else {
                    if (rastro[i][j] >= 4) printf("@");
                    else if (rastro[i][j] >= 3) printf("#");
                    else if (rastro[i][j] >= 2) printf("*");
                    else if (rastro[i][j] >= 1) printf(".");
                    else printf(" ");
                }
            }
            printf("\n");
        }

        printf("Vida: %d\n", vida);

        pausar(40);
    }

    return 0;
}