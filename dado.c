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

char nome[25] = { "Sem nome" };


int main()
{
#ifdef _WIN3299
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

	printf
		("pegue essa poção e beba, é sangue de dragão dourado, ela irá aumentar seu nível.");

	int pocao = 5;
	int nv_jogador = 1;
	int pts_atributos = 0;
	int pts_experiencia = 0;

	do
	{
		printf("tomar poção? (s|n) ");
		scanf("%c", &decisao[2]);
		if (decisao[2] == 's')
		{
			nv_jogador++;
			pocao--;
			pts_atributos += 5;
		}
		else if (decisao[2] == 's')
		{
			pocao = 0;
		}
		else
		{
			printf("Não entendi a sua resposta . . .\n");
			decisao[2] == 's';
		}
	}
	while (decisao[2] == 's' && pocao > 0);

	swhit(decisao[3])
	{
		
	}

	int inteligencia = 1;
	int forca = 1;
	int agilidade = 1;
	int destreza = 1;
	int vitalidade = 1;
	int sorte = 1;

	/* - - - - - - - - - - - - - */

	int nivelMons = 5;

	int intMosn = (rand() % nivelMons) + 1;
	int forMosn = (rand() % nivelMons) + 1;
	int agiMons = (rand() % nivelMons) + 1;
	int desMons = (rand() % nivelMons) + 1;p
	int vitMons = (rand() % nivelMons) + 1;
	int sorMons = (rand() % nivelMons) + 1;

	/* - - - - - - - - - - - - - */

	int NV = 0;
	int INT = 0;
	int FOR = 0;
	int DES = 0;
	int AGI = 0;
	int VIT = 0;
	int SOR = 0;

	float atq_fis = (FOR * 1) + (DES / 2) + SOR;
	float atq_mag = (INT * 2) + (DES / 2) + SOR;

	float def = ((VIT * 3) + (FOR / 2) + (AGI * 2) + NV) * 100;

	float vida_max = (VIT * 3 + NV * 2) * 100;
	float mana_max = (INT * 3 + NV * 2) * 100;

	float dano_fis = atq_fis - def;
	float dano_mag = atq_mag - def;



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







	do
	{

	}
	while (decisao[2] == 's');
	return 0;
}
