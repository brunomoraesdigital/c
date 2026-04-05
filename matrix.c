#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep(ms * 1000)
    #define CLEAR "clear"
#endif

#define LARGURA 80
#define ALTURA 25

int main() {
    int gotas[LARGURA];
    srand(time(NULL));

    // Inicializa as gotas no topo (valor negativo para dar atraso aleatório)
    for (int i = 0; i < LARGURA; i++) {
        gotas[i] = rand() % ALTURA;
    }

    // Cor verde no terminal (funciona na maioria dos terminais modernos)
    printf("\033[1;32m");

    while (1) {
        system(CLEAR);

        for (int y = 0; y < ALTURA; y++) {
            for (int x = 0; x < LARGURA; x++) {
                // Se a gota está nesta linha, desenha um caractere aleatório
                if (gotas[x] == y) {
                    printf("%c", (rand() % 94) + 33); // Caracteres ASCII visíveis
                } else if (gotas[x] > y && gotas[x] < y + 5) {
                    // Desenha o "rastro" da gota
                    printf(".");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        // Move as gotas para baixo
        for (int i = 0; i < LARGURA; i++) {
            gotas[i]++;
            // Se chegou no final, volta para o topo com posição aleatória
            if (gotas[i] >= ALTURA + 5) {
                gotas[i] = 0;
            }
        }

        SLEEP(50); // Ajuste a velocidade aqui
    }

    return 0;
}
