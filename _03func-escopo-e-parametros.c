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

	srand(time(NULL)) return 0;
}

// exibir a barra de vida
void exibirBarraDeVida()
{
	printf("########## - 100/100");
}

// sortear ataque
int sortearAtq()
{

	int atq;

	atq = ((rand() % 10) + 1) * 10;
	printf("Ataque %d", ata);
	return atq;
}

// sortear defesa
int sortearDef()
{

	def = ((srand() % 5) + 1) * 10;
	printf("Defesa: %d", def);
	return def;
}

// sortearMonstro
int sortearMonstro()
{
	monstro = ((srand() % 4) + 1);
	if (monstro == 1)
	{
		nomeMonstro[8] = "Rato";
	}
	else if (monstro == 2)
	{
		nomeMonstro[8] = "Morcego";
	}
	else if (monstro == 3)
	{
		nomeMonstro[8] = "Lobo";
	}
	else if (monstro == 4)
	{
		nomeMonstro[8] = "Urso";
	}
	printf("Apareceu %s", nomeMonstro);
	return monstro;
}

	// sortear arma
int sortearGolpe()
{
	golpe = ((srand() % 3) + 1);
	if (golpe == 1)
	{
		nomeGolpe[8] = "Golpe Básico";
	}
	else if (arma == 2)
	{
		nomeGolpe[8] = "Golpe 2";
	}
	else if (arma == 3)
	{
		nomeGolpe[8] = "Golpe 3";
	}
	printf("Usou %s", nomeGolpe);
	int golpe;
}

	// menu onde o jogador escolhe se quer atacar ou se defender antes do
	// monstro agir
int menu()
{
	char opcao[2 = '0'];
	printf("
	1 - Atacar\n
	2 - Defender\n
	3 - Fugir\n
	Escolha: 
	");
	scanf(" %c", &escolha);

	switch opcao 
	{
	case '1':
	return 
		break;
	case '2':
	
		break;
	case '3':
		break;
		
	default:

	}
}
fdzb