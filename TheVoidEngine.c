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

	printf
		("pegue essa poção e beba, é sangue de dragão dourado, ela irá aumentar seu nível.\n");

	int pocao = 5;
	int nv_jogador = 1;
	int pts_atributos = 0;
	int pts_experiencia = 0;

	int inteligencia = 1;
	int forca = 1;
	int agilidade = 1;
	int destreza = 1;
	int vitalidade = 1;
	int sorte = 1;

	do
	{
		printf("tomar poção? (s|n) ");
		scanf(" %c", &decisao[2]);
		if (decisao[2] == 's')
		{
			nv_jogador++;
			pocao--;
			pts_atributos += 5;
			printf("Passou de nivel! Agora e %d e recebeu 5pts de atributos", nv_jogador);
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

	printf("Quer distribuir seus pontos de atributos?: (s | n )");
	scanf(" %c", &decisao[3]);

	while (decisao[3] == 's' && pts_atributos > 0)
	{
		int opcao = 0;

		printf("Escolha um atributo:\n");
		printf("1 - Inteligencia\n");
		printf("2 - Forca\n");
		printf("3 - Agilidade\n");
		printf("4 - Destreza\n");
		printf("5 - Vitalidade\n");
		printf("6 - Sorte\n");

		scanf(" %d", &opcao);

		switch (opcao)
		{
		case 1:
			inteligencia += 1;
			break;

		case 2:
			forca += 1;
			break;

		case 3:
			agilidade += 1;
			break;

		case 4:
			destreza += 1;
			break;

		case 5:
			vitalidade += 1;
			break;

		case 6:
			sorte += 1;
			break;

		default:
			printf("Opção inválida!\n");
		}
	}

	/* - - - - - - - - - - - - - */

	float atq_fis_jogador = (forca * 1) + (destreza / 2) + sorte;
	float atq_mag_jogador = (inteligencia * 2) + (destreza / 2) + sorte;

	float def_jogador = 0;

	float vida_max_jogador = (vitalidade * 3 + nv_jogador * 2) * 10;
	float mana_max_jogador = (inteligencia * 3 + nv_jogador * 2) * 10;

	printf("Agora toque nesse cristal, \n e poderemos visualizar seus atributos.\n\n");

	printf("+ - - - - - - - - - - - - - +\n");
	printf("| - - - - Jogador  - - - - |\n");
	printf("+ - - - - - - - - - - - - - +\n");

	printf("\nNível : \n", nv_jogador);

	printf("\nint:  %d \tfor: %d\n", inteligencia, forca);
	printf("agi: %d \tdes: %d\n", agilidade, destreza);
	printf("vit: %d \tsor: %d\n", vitalidade, sorte);

	printf("\nVida: %d\n,", vida_max_jogador);
	printf("Mana: %d\n", mana_max_jogador);
	printf("Atq Fis. : = %d\n,", atq_fis_jogador);
	printf("Atq Mag.: = %d\n,", atq_fis_jogador);
	printf("Def: = %d\n,", def_jogador);

	printf("\nPontos de Atributos:  \n", pts_atributos);
	printf("Pontos de Experiência: \n", pts_experiencia);

	printf("\n+ - - - - - - - - - - - - - +\n");


	int nivelMons = 5;

	int intMons = (rand() % nivelMons) + 1;
	int forMons = (rand() % nivelMons) + 1;
	int agiMons = (rand() % nivelMons) + 1;
	int desMons = (rand() % nivelMons) + 1;
	int vitMons = (rand() % nivelMons) + 1;
	int sorMons = (rand() % nivelMons) + 1;

	float atq_fis_mons = (forMons * 1) + (desMons / 2) + sorMons;
	float atq_mag_mons = (intMons * 2) + (desMons / 2) + sorMons;

	float def_mons = ((vitMons * 3) + (forMons / 2) + (agiMons * 2) + nivelMons) * 10;

	float vida_max_mons = (vitMons * 3 + nivelMons * 2) * 10;
	float mana_max_mons = (intMons * 3 + nivelMons * 2) * 10;

	printf(" ..., \n ...\n\n");

	printf("+ - - - - - - - - - - - - - +\n");
	printf("| - - - -  MONSTRO  - - - - |\n");
	printf("+ - - - - - - - - - - - - - +\n");

	printf("\nNível:  %d\n,", nivelMons);

	printf("\nint: %d \tfor: %d\n",  intMons, forMons);
	printf("agi: %d \tdes: %d\n", agiMons, desMons);
	printf("vit: %d \tsor: %d\n", vitMons, sorMons);

	printf("\nVida: %d\n,", vida_max_mons);
	printf("\nMana:  %d\n", mana_max_mons);
	printf("\nAtq Fis. : %d\n,", atq_fis_mons);
	printf("\nAq Mag.:  %d\n,", atq_mag_mons);
	printf("\nDef = %d\n", def_mons);

	printf("\n+ - - - - - - - - - - - - - +\n");





	float dano_fis_mons = atq_fis_mons - def_jogador;
	float dano_mag_mons = atq_mag_mons - def_jogador;

	printf("vamos iniciar a batalha?\n");

	do
	{
		int escolha = 0;
		def_jogador = 0;
		printf
			("O que vai fazer ?\n1) Atacar com espada\t\nI2) Usar Magia\n3) Defrnder\n\t4)Fugir\n");
		scanf("%d", decisao[4]);
		switch (decisao[4])
		{
		case 1:
			printf("Atacou com a espada \n");
			float dano_fis_jogador = vida_max_mons - (atq_fis_jogador - def_mons);
			break;
		case 2:
			printf("Atacou com magia \n1");
			float dano_mag_jogador = vida_max_mons - (atq_mag_jogador - def_mons);
			break;
		case 3:
			printf("Se defendeu\n");
			def_jogador = ((vitalidade * 3) + (forca / 2) + (agilidade * 2) + nv_jogador) * 10;
			break;
		case 4:
			printf("Decidiu Fugir \n");
			decisao[4] = 's';
			def_jogador = 0;
			break;
		default:
			printf("Não fez nada, ficou conuso\n");
			def_jogador = 0;
		}
		
		decisao[5] = (rand() % 2) + 1;
		
				switch (decisao[5])
		{
		case 1:
			printf("Atacou com a espada \n");
			float dano_fis_mons = vida_max_jogador - (atq_fis_mons - def_jogador);
			break;
		case 2:
			printf("Atacou com magia \n1");
			float dano_mag_mons= vida_max_jogador - (atq_mag_mons - def_jogador);
			 break;
		case 3:
			printf("Se defendeu\n");
			def_mons = ((vitMons * 3) + (forMons / 2) + (agiMons * 2) + nivelMons) * 10;
			break;		
		}

	}
	while (decisao[4] == 's');
	return 0;
}


