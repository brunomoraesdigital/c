#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    srand(time(NULL));

    int pontuacao = 0;
    float energia = 100;
    int escolha;
    int percorrido = 0;

    while (energia > 0 && pontuacao < 50)
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        printf("Dino C Run 🦖\n");
        printf("- - - - - - - - - - - - - - - - -\n");
        printf("❤️ Energia: %.1f || 🌟 Pontos: %d\n", energia, pontuacao);
        printf("- - - - - - - - - - - - - - - - -\n");

        int corrida = (rand() % 6) + 5;

        printf("correndo ");

        for (int i = 1; i <= corrida; i++)
        {
            percorrido++;
            printf(" %dm ", percorrido);
            fflush(stdout);

#ifdef _WIN32
            Sleep(400);
#else
            usleep(400000);
#endif
        }

        printf("\n");

        int evento = rand() % 2;

        if (evento == 0)
        {
            printf("🌵 Um cacto apareceu!\n");
            printf("(1 - Pular | 2 - Atropelar): ");
        }
        else
        {
            printf("🦅 Um abutre apareceu!\n");
            printf("(1 - Abaixar | 2 - Colidir): ");
        }

        scanf("%d", &escolha);

        if (escolha == 1)
        {
            printf("\nAção correta!\n");
            printf("+%d pontos\n", corrida);
            pontuacao += corrida;

#ifdef _WIN32
            Sleep(2000);
#else
            sleep(2);
#endif
        }
        else if (escolha == 2)
        {
            if (evento == 0)
            {
                printf("\nVocê bateu no cacto!\n-10 de energia\n");
                energia -= 10;
            }
            else
            {
                printf("\nVocê bateu no abutre!\n-20 de energia\n");
                energia -= 20;
            }

#ifdef _WIN32
            Sleep(2000);
#else
            sleep(2);
#endif
        }
        else
        {
            printf("\nComando inválido!\n-15 de energia\n");
            energia -= 15;

#ifdef _WIN32
            Sleep(2000);
#else
            sleep(2);
#endif
        }

        if (energia <= 0)
        {
            printf("\nEnergia esgotada!\n");
            printf("GAME OVER ☠️\n");
            return 0;
        }

        if (pontuacao >= 50)
        {
            printf("\nVocê atingiu %d pontos!\n", pontuacao);
            printf("VOCÊ GANHOU! 🏆\n");
            return 0;
        }
    }

    return 0;
}
