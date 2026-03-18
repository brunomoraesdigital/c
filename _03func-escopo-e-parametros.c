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

void desenharBarra(int vidaAtual, int atqAtual, int defAtual)
{
	char coracao[] = "❤️";
	char espada[] = "🗡️";
	char escudo[] = "🛡️";
	char barraCheia[] = "█";
	char barraVazia[] = "░";
	int quantidadeBlocos = 10;
	int valorAtual = 0;
	int vidaMax = 100;

	int i;
	int j;

	printf("\n - - - - - - - - - - - - -\n");
	for (j = 0; j < 3; j++)
	{
		if (j == 0)
		{
			printf(" %s", coracao);
			valorAtual = vidaAtual;
		}
		else if (j == 1)
		{
			printf(" %s", espada);
			valorAtual = atqAtual;
		}
		else
		{
			printf(" %s", escudo);
			valorAtual = defAtual;
		}
		printf(" | ");

		int preenchido = (valorAtual * quantidadeBlocos) / vidaMax;
		int naoPreenchido = quantidadeBlocos - preenchido;

		for (i = 0; i < preenchido; i++)
		{
			printf("%s", barraCheia);
		}

		for (i = preenchido; i < quantidadeBlocos; i++)
		{
			printf("%s", barraVazia);
		}
		printf(" - %d/100", valorAtual);
		printf("\n - - - - - - - - - - - - -\n");
	}
}

void sortearAtributo()
{
	srand(time(NULL));
	
	return int atributo = (rand() % modificador) + 1;
}

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	desenharBarra(10, 30, 40);

	return 0;
}
