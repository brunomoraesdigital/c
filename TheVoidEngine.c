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

void exibirBarraVida();
void calcularDano();
void gerarMonstro();

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	exibirBarraVida();
	calcularDano();
	gerarMonstro();

	return 0;
}


char vidaBarra[11] = { "##########" };

int vidaValor = 100;
int def;
int atq;
int i = 0;

// exibirBarraVida: Uma função que desenha o status (ex: [##### ] 50/100).
void exibirBarraVida()
{
	printf("[");
	for (i = 0; i < 10; i++)
	{
		printf("%c", vidaBarra[i]);
	}
	printf("] %d/100", vidaValor);
}

// calcularDano: Uma função que recebe ataque e defesa e retorna o valor
// final.
void calcularDano()
{
	vidaValor = 100;
	int def = ((rand() % 10) + 1)*5;
	printf("\n%d", def);
}

// gerarMonstro: Uma função que sorteia o nome e poder do inimigo.
void gerarMonstro()
{
	int atq = ((rand() % 10) + 1)*10;
	printf("\n%d", atq);
}
