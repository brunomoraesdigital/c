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

int pntAtributos = 0;

char nome[25] = { "Sem nome" };

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	char decisaoA = 'n';
	char decisaoB = 'n';
	do
	{
		printf("Quer definir um nome? ");
		scanf(" %c", &decisaoA);
		if (decisaoA == 's')
		{
			printf("Qual o seu nome? ");
			scanf(" %24s", nome);
		}
		else if (decisaoA == 'n')
		{
			printf("Escolheu não definir o nome\n");
		}
		else
		{
			printf("Resposta irreconhecivel\n");
		}
		printf("Aventureiro %s,\n ",  nome);
		printf("Confirma seu nome? ");
		scanf(" %c", &decisaoB);
	}
	while (decisaoB == 'n');
	return 0;
}
