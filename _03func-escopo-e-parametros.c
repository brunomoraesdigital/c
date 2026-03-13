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

void exibirBarraDeVida(int atq, int def, int vida)
{
	printf("❤️ | ########## - %d/100", vida);
	printf("\n🗡️ | ########## - %d/100", atq);
	printf("\n🛡️ | ########## - %d/100", def);
}

int sortearValor(int intervalo, int multiplicador)
{
	int numSorteado = ((rand() % intervalo) + 1) * multiplicador;
	return numSorteado;
}

int sortearVida()
{
	int vida = sortearValor(10, 10);
	return vida;
}

int sortearAtq()
{
	int atq = sortearValor(10, 10);
	return atq;
}

int sortearDef()
{
	int def = sortearValor(5, 10);
	return def;
}

char *sortearMonstro()
{
	int valor = sortearValor(4, 1);

	switch (valor)
	{
	case 1:
		return "Rato";
	case 2:
		return "Morcego";
	case 3:
		return "Lobo";
	case 4:
		return "Urso";
	default:
		return "Desconhecido";
	}
}

void monstro()
{
	char *monstro = sortearMonstro();

	printf("\n\nVocê encontrou um %s!\n", monstro);

	int atq = sortearAtq();
	int def = sortearDef();
	int vida = sortearVida();

	exibirBarraDeVida(atq, def, vida);
}

char *sortearArma()
{
	int valor = sortearValor(4, 1);

	switch (valor)
	{
	case 1:
		return "uma Faca";
	case 2:
		return "uma Espada";
	case 3:
		return "um Mangual";
	case 4:
		return "um Arco";
	default:
		return "Desconhecido";
	}
}

void jogador()
{
	char nome[10] = { "William" };
	char *arma = sortearArma();
	printf("Jogador: %s tem %s \n", nome, arma);

	int atq = sortearAtq();
	int def = sortearDef();
	int vida = sortearVida();

	exibirBarraDeVida(atq, def, vida);
}

int sorteioAcoesBatalha()
{
	int monstroAtacando;
	int escolha;
	if (monstroAtacando == 1) {
	int valor = sortearValor(4, 1);
	} else {
		scanf("%d",  &escolha);
	switch (escolha)
	{
	  case 1: return 1;
	  case 2: return 2;
	  case 3: return 3;
	  case 4: return 4;
	  default: 
	  return 0;
	}
}

void batalha()
{

}


int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	srand(time(NULL));

	jogador();
	monstro();

	return 0;
}
