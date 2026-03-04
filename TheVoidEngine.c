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
int calcularDano();
int gerarMonstro();

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	srand(time(NULL));			// ← faltou isso

	exibirBarraVida();


	return 0;
}


char vidaBarra[11];

int vidaValor = 100;
int def;
int atq;
int dano;
int i;
int j;

// exibirBarraVida: Uma função que desenha o status (ex: [##### ] 50/100).
void exibirBarraVida()
{
	do {
			calcularDano();
			
	vidaValor -= dano;
	j = vidaValor / 10;

	printf("\n[");
	for (i = 0; i < j; i++)
	{
		printf("%c", vidaBarra[i] = '#');
	}
		for (i = j; i < 10; i++)
	{
		vidaBarra[i] = '-';
		printf("%c", vidaBarra[i]);
	}
	printf("] %d/100", vidaValor);
	} while (j > 0);
}

// calcularDano: Uma função que recebe ataque e defesa e retorna o valor
// final.
int calcularDano()
{
	gerarMonstro();
	def = ((rand() % 5) + 1) * 10;

	printf("\n\nDefesa: %d\n", def);
	printf("Ataque: %d\n", atq);

	if (def >= atq)
	{
		printf("\nDefendido");
		dano = 0;
		printf("Dano: %d", dano);
	}
	else
	{
		dano = atq - def;
		printf("Dano: %d\n", dano);
	}

}

// gerarMonstro: Uma função que sorteia o nome e poder do inimigo.
int gerarMonstro()
{
	atq = ((rand() % 10) + 1) * 10;
	return atq;
}
