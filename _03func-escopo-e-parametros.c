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

void exibirBarraDeVida();

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	exibirBarraDeVida();

	return 0;
}

// exibir a barra de vida
void exibirBarraDeVida()
{
	printf("########## - 100/100");
}

// sortear ataque
int sortearAtqDef()
{

	atq = ((srand() % 10) + 1) * 10;

	return atq;
}

// sortear defesa
int sortearAtqDef()
{

	def = ((srand() % 5) + 1) * 10;

	return def;
}

// sortearMonstro
int sortearMonstro()
{
	monstro = ((srand() % 4) + 1) ; 
	if (monstro == 1) {
		nomeMontro[8] = {"Rato"};
	} else if (monstro == 2) {
		nomeMontro[8] = {"Morcego"};
	} else if (monstro == 3) {
		nomeMontro[8] = {"Lobo"};
	} else if (monstro == 4) {
		nomeMontro[8] = {"Urso"};
	}
	return nomeMontro[8];
}

// sortear arma
int sortearArma()
{
	arma = ((srand() % 3) + 1) ; 
	if (arma == 1) {
		nomeArma[8] = {"faca"};
	} else if (arma == 2) {
		nomeArma[8] = {"espada"};
	} else if (arma == ) {
		nomeArma[8] = {"porrete"};
	}
	return nomeArma[8];
}

// menu onde o jogador escolhe se quer atacar ou se defender antes do monstro
// agir
