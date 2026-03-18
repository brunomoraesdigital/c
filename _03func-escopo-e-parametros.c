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

char coracao[] = "❤️";
char espada[] = "🗡️";
char escudo[] = "🛡️";
char barraCheia[] = "█";
char barraVazia[] = "░";
int vidaAtual = 50;
int quantidadeBlocos = 10;;
int vidaMax = 100;


void desenharBarra()
{
	int i;
	int preenchido = (vidaAtual * quantidadeBlocos) / vidaMax;
	int naoPreenchido = 10 - preenchido;
	int j;

	for (j = 0; j < 3; j++)
	{
		if (j == 0)
		{
			printf(" %s", coracao);
		}
		else if (j == 1)
		{
			printf(" %s", espada);
		}
		else
		{
			printf(" %s", escudo);
		}
		printf(" | ");
		for (i = 0; i < preenchido; i++)
		{
			printf("%s", barraCheia);
		}
		printf(" - %d/100", vidaAtual);
		for (i = preenchido; i < naoPreenchido; i++)
		{
			printf("%s", barraCheia);
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
