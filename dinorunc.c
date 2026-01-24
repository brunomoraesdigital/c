#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
	srand(time(NULL));			// ??

	int pontuacao = 0;
	float energia = 100;
	int nivel = 1;
	int escolha;
	int sorteio;
	int jogoAtivo = 1;
	int percorrido = 0;


	printf("Dino C Run 🦖\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("Energia: %.1f\n", energia);
	printf("Pontuação: %d\n\n", pontuacao);

	while (energia > 0 && pontuacao < 50)
	{
		system("cls");
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
			fflush(stdout);		// força imprimir agora
			usleep(400000);		// 0.4 segundos
		}

		printf(" ");

		int evento = rand() % 2;

		if (evento == 0)
		{
			printf("🌵 \n");
			printf(" \n 🌵 Um cacto apareceu! (1 - Pular | 2 - Atropelar): ");
		}
		else
		{
			printf("🦅 \n");
			printf(" \n 🦅 Um abutre apareceu! (1 - Abaixar | 2 - Colidir): ");
		}

		scanf("%d", &escolha);

		if (escolha == 1)
		{
			if (evento == 0)
			{
				printf(" \nVocê saltou com perfeicão! ganhou %d\n", corrida);
				pontuacao = percorrido;
				sleep(3);
			}
			else
			{
				printf("\nVocê abaixou com perfeição! %d\n", corrida);
				pontuacao = percorrido;
				sleep(3);
			}
		}
		else if (escolha == 2)
		{
			if (evento == 0)
			{
				printf(" Você bateu no cacto! \n ");
				printf(" -10 de energia \n ");
				energia = energia - 10;
			}
			else
			{
				printf(" Você bateu no abutre! \n ");
				printf(" -20 de energia \n ");
				energia = energia - 20;
			}

		}
		else
		{
			if (evento == 0)
			{
				printf(" Comando inválido! \n ");
				printf(" O Dino ficou confuso e atropelou o cacto! \n ");
				printf(" -15 de energia \n ");
				energia = energia - 15;
			}
			else
			{
				printf(" Comando inválido ! \n ");
				printf(" O Dino ficou confuso e colidiu no abutre ! \n ");
				printf(" - 25 de energia\n ");
				energia = energia - 25;
			}

		}


		/* Verificação de GAME OVER */
		if (energia <= 0)
		{
			printf(" \nEnergia esgotada!\n ");
			printf("GAME OVER\n ");
			return 0;
		}

		/* Verificação de VOCÊ GANHOU */
		if (pontuacao >= 50)
		{
			printf(" \nAtingiu % d metros \n ", pontuacao);
			printf(" VOCÊ GANHOU ! 🏆\n ");
			return 0;
		}

		/* Status final */
		printf(" \nStatus Atualizado: \n ");
		printf("Energia: %.1f \n ", energia);
		printf("Pontuação:%d \n ", pontuacao);

	}
	return 0;

}
