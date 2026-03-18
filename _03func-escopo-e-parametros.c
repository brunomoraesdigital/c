#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
// Sistema: Windows
#include <windows.h>
#else
// Sistema: Linux / Android
#include <unistd.h>
#endif

void desenharBarra()
{
	char coracao[] = "❤️";
	char espada[] = "🗡️";
	char escudo[] = "🛡️";
	char barraCheia[] = "█";
	char barraVazia[] = "░";
	int quantidadeBlocos = 10;
	int desenha = 0;
	int vidaMax = 100;
	int vidaAtual = 10;
	int atqAtual = 40;
	int defAtual = 30;
	
	int i;
	int j;
	
	for (j = 0; j < 3; j++)
	{
		if (j == 0)
		{
			printf(" %s", coracao);
			desenha = vidaAtual;
		}
		else if (j == 1)
		{
			printf(" %s", espada);
			desenha = atqAtual;
		}
		else
		{
			printf(" %s", escudo);
			desenha = defAtual;
		}
		printf(" | ");

		int preenchido = (desenha * quantidadeBlocos) / vidaMax;
		int naoPreenchido = quantidadeBlocos - preenchido;

		for (i = 0; i < preenchido; i++)
		{
			printf(" %s", barraCheia);
		}

		for (i = preenchido; i < quantidadeBlocos; i++)
		{
			printf(" %s", barraVazia);
		}
		printf(" - %d/100", vidaAtual);
		printf("\n");
	}
}


int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	srand(time(NULL));

	desenharBarra(10, 10, 10);

	return 0;
}
