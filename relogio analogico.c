#include <stdio.h>
#include <math.h>
#include <time.h>

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

void desenhar_linha(char tela[ALTURA][LARGURA], int x0, int y0, int x1, int y1, char c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        if (x0 >= 0 && x0 < LARGURA && y0 >= 0 && y0 < ALTURA)
            tela[y0][x0] = c;

        if (x0 == x1 && y0 == y1) break;

        e2 = 2 * err;

        if (e2 >= dy) {
            err += dy;
            x0 += sx;
        }

        if (e2 <= dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    while (1) {

        char tela[ALTURA][LARGURA];
        int x, y;

        // limpa buffer
        for (y = 0; y < ALTURA; y++)
            for (x = 0; x < LARGURA; x++)
                tela[y][x] = ' ';

        int cx = LARGURA / 2;
        int cy = ALTURA / 2;
        int raio = 10;

        // desenha círculo
        for (int ang = 0; ang < 360; ang += 5) {
            float rad = ang * 3.14159 / 180;
            int px = cx + cos(rad) * raio;
            int py = cy + sin(rad) * raio;

            if (px >= 0 && px < LARGURA && py >= 0 && py < ALTURA)
                tela[py][px] = 'o';
        }

        // pega hora atual
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);

        int seg = tm->tm_sec;
        int min = tm->tm_min;
        int hora = tm->tm_hour % 12;

        // ângulos
        float ang_seg = (seg / 60.0) * 2 * 3.14159;
        float ang_min = (min / 60.0) * 2 * 3.14159;
        float ang_hor = ((hora + min / 60.0) / 12.0) * 2 * 3.14159;

        // ponteiros
        int sx = cx + cos(ang_seg - 3.14159/2) * (raio - 1);
        int sy = cy + sin(ang_seg - 3.14159/2) * (raio - 1);

        int mx = cx + cos(ang_min - 3.14159/2) * (raio - 2);
        int my = cy + sin(ang_min - 3.14159/2) * (raio - 2);

        int hx = cx + cos(ang_hor - 3.14159/2) * (raio - 4);
        int hy = cy + sin(ang_hor - 3.14159/2) * (raio - 4);

        desenhar_linha(tela, cx, cy, sx, sy, '.'); // segundos
        desenhar_linha(tela, cx, cy, mx, my, '*'); // minutos
        desenhar_linha(tela, cx, cy, hx, hy, '#'); // horas

        limpar_tela();

        for (y = 0; y < ALTURA; y++) {
            for (x = 0; x < LARGURA; x++) {
                printf("%c", tela[y][x]);
            }
            printf("\n");
        }

        pausar(1000);
    }

    return 0;
}