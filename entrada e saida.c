#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_FRASES 100
#define TAM_FRASE 200

void pausar(int milissegundos)
{
#ifdef _WIN32
	Sleep(milissegundos);
#else
	usleep(milissegundos * 1000);
#endif
}

void digitar(const char *texto, int velocidade)
{
	for (int i = 0; i < strlen(texto); i++)
	{
		printf("%c", texto[i]);
		fflush(stdout);
		pausar(velocidade);
	}
}

void limpar_tela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void armazenar_e_exibir()
{
	char frases[MAX_FRASES][TAM_FRASE];
	int total = 0;

	while (1)
	{
		printf("Digite uma frase (ENTER vazio para parar): ");

		if (fgets(frases[total], TAM_FRASE, stdin) == NULL)
		{
			break;
		}

		if (frases[total][0] == '\n')
		{
			break;
		}

		frases[total][strcspn(frases[total], "\n")] = '\0';

		total++;

		if (total >= MAX_FRASES)
		{
			printf("Limite atingido!\n");
			break;
		}
	}

	limpar_tela();

	printf("=== Exibindo frases ===\n\n");

	for (int i = 0; i < total; i++)
	{
		digitar(frases[i], 30);
		printf("\n");
	}
}

int main()
{
	armazenar_e_exibir();
	return 0;
}