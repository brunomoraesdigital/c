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


int nivelPersonagem = 1;
int pontosAtributos = 0;
int pontosExperiencia = 0;


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
		printf("\nAventureiro %s,\n ", nome);
		printf("Podemos continuar? (s|n)");
		scanf(" %c", &decisao[1]);
	}
	while (decisao[1] == 'n');

	printf("\nConcluído essa fase\n podemos ir adianter!\n");

	printf("pegue essa poção e beba, é sangue de dragão, ela irá aumentar seus atributos temporariamente");

		inteligencia = (rand() % 10) + 1;
		forca = (rand() % 10) + 1;
		agilidade = (rand() % 10) + 1;
		destreza = (rand() % 10) + 1;
		vitalidade = (rand() % 10) + 1;
		sorte = (rand() % 10) + 1;



	printf("Agora toque nesse cristal, \n e poderemos visualizar seus atributos.\n\n");

	printf("+ - - - - - - - - - - - - - +\n");
	printf("| - - - - Atributos - - - - |\n");
	printf("+ - - - - - - - - - - - - - +\n");

	printf("\nNível = 1\n");

	printf("\nint = %d \tfor= %d\n", inteligencia, forca);
	printf("agi = %d \tdes= %d\n", agilidade, destreza);
	printf("vit = %d \tsor = %d\n", vitalidade, sorte);

	printf("\nPontos de Atributos= 0\n");
	printf("Pontos de Experiência = 0\n");

	printf("\n+ - - - - - - - - - - - - - +\n");
	
	printf("\nVoce está pronto para a batalha? ");
	scanf(" %c", &decisao[2]);
	
	    int intMosn = (rand() % 10) + 1;
		int forMosn = (rand() % 10) + 1;
		int agiMons = (rand() % 10) + 1;
		int desMons = (rand() % 10) + 1;
		int vitMons = (rand() % 10) + 1;
		int sorMons = (rand() % 10) + 1;
	
	do {
		
	} while (decisao[2] == 's');

	return 0;
}

