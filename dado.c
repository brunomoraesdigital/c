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

int inteligencia = 1;
int forca = 1;
int agilidade = 1;
int destreza = 1;
int vitalidade = 1;
int sorte = 1;

int nvlPersonagem = 1;

int pontosAtributos[];

char nome[25] = { "Sem nome" };


int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	char decisao[25];

	int i;
	for (i = 0; i < 25; i++)
	{
		decisao[i] = 'n';
	}

	do
	{
		printf("Quer registrar seu nome? (s|n) ");
		scanf(" %c", &decisao[0]);
		if (decisao[0] == 's')
		{
			printf("Qual o seu nome? ");
			scanf(" %24s", nome);

		}
		else if (decisao[0] == 'n')
		{
			printf("Escolheu não registrar um nome\n");

		}
		else
		{
			printf("Não foi possível compreender sua resposta\n");

		}
		printf("Aventureiro %s,\n ", nome);
		printf("Podemos continuar? (s|n)");
		scanf(" %c", &decisao[1]);
	}
	while (decisao[1] == 'n');

	printf("Boas vindas! Podemos prosseguir!\n");

	do
	{
		printf("Quer conhecer seus\n atributos iniciais? (s|n)");
		scanf(" %c", &decisao[2]);
		if (decisao[2] = 's');
		for (i = 0; i < 10; i++)
		{
			pontosAtributos[i] = rand() % 10 + 1;
		}
		
	}
		while (decisao[3] == 'n');
		return 0;
	}
