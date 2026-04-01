#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif

#define LARGURA 67
#define ALTURA 25

#define MAX_COBRA 1000

typedef struct {
    int x;
    int y;
} Parte;

Parte cobra[MAX_COBRA];

int tamanho = 5;
int direcao_x = 1;
int direcao_y = 0;

int comida_x, comida_y;

// ===============================
void dormir(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

// ===============================
#ifndef _WIN32
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int getch(void) {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
#endif

// ===============================
void limpar() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ===============================
void gerar_comida() {
    int i, valido;

    do {
        valido = 1;

        comida_x = rand() % (LARGURA - 2) + 1;
        comida_y = rand() % (ALTURA - 2) + 1;

        // verifica se nasceu em cima da cobra
        for (i = 0; i < tamanho; i++) {
            if (cobra[i].x == comida_x && cobra[i].y == comida_y) {
                valido = 0;
                break;
            }
        }

    } while (!valido);
}

// ===============================
void inicializar() {
    int i;
    for (i = 0; i < tamanho; i++) {
        cobra[i].x = 10 - i;
        cobra[i].y = 10;
    }

    gerar_comida();
}

// ===============================
void desenhar() {
    int x, y, i;

    limpar();

    for (y = 0; y < ALTURA; y++) {
        for (x = 0; x < LARGURA; x++) {

            if (y == 0 || y == ALTURA - 1 || x == 0 || x == LARGURA - 1) {
                printf("#");
                continue;
            }

            if (x == comida_x && y == comida_y) {
                printf("*");
                continue;
            }

            int desenhado = 0;
            for (i = 0; i < tamanho; i++) {
                if (cobra[i].x == x && cobra[i].y == y) {
                    printf(i == 0 ? "O" : "o");
                    desenhado = 1;
                    break;
                }
            }

            if (!desenhado) printf(" ");
        }
        printf("\n");
    }

    printf("\nTeclas da esquerda = virar esquerda\nTeclas da direita = virar direita\n");
}

// ===============================
void virar_esquerda() {
    if (direcao_x == 1) { direcao_x = 0; direcao_y = -1; }
    else if (direcao_x == -1) { direcao_x = 0; direcao_y = 1; }
    else if (direcao_y == 1) { direcao_x = 1; direcao_y = 0; }
    else if (direcao_y == -1) { direcao_x = -1; direcao_y = 0; }
}

void virar_direita() {
    if (direcao_x == 1) { direcao_x = 0; direcao_y = 1; }
    else if (direcao_x == -1) { direcao_x = 0; direcao_y = -1; }
    else if (direcao_y == 1) { direcao_x = -1; direcao_y = 0; }
    else if (direcao_y == -1) { direcao_x = 1; direcao_y = 0; }
}

// ===============================
void entrada() {
    if (kbhit()) {
        char t = getch();

        if (t == 'q' || t == 'w' || t == 'e' || t == 'a' || t == 's' || t == 'd' || t == 'z' || t == 'x' || t == 'c') {
            virar_esquerda();
        }
        else if (t == 'i' || t == 'o' || t == 'p' || t == 'j' || t == 'k' || t == 'l' || t == 'b' || t == 'n' || t == 'm') {
            virar_direita();
        }
    }
}

// ===============================
void atualizar() {
    int i;

    for (i = tamanho - 1; i > 0; i--) {
        cobra[i] = cobra[i - 1];
    }

    cobra[0].x += direcao_x;
    cobra[0].y += direcao_y;

    // atravessar paredes
    if (cobra[0].x <= 0) cobra[0].x = LARGURA - 2;
    if (cobra[0].x >= LARGURA - 1) cobra[0].x = 1;

    if (cobra[0].y <= 0) cobra[0].y = ALTURA - 2;
    if (cobra[0].y >= ALTURA - 1) cobra[0].y = 1;

    // colisão com corpo
    for (i = 1; i < tamanho; i++) {
        if (cobra[0].x == cobra[i].x && cobra[0].y == cobra[i].y) {
            printf("\n💀 Game Over!\n");
            exit(0);
        }
    }

    // comer comida
    if (cobra[0].x == comida_x && cobra[0].y == comida_y) {
        tamanho++;
        gerar_comida();
    }
}

// ===============================
int main() {
    srand(time(NULL));

    inicializar();

    while (1) {
        entrada();
        atualizar();
        desenhar();
        dormir(80);
    }

    return 0;
}