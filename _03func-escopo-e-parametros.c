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
int sortearAtq();
int sortearDef();

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif
	exibirBarraDeVida();

	srand(time(NULL));

	sortearAtq();

	sortearDef();

	return 0;
}


void exibirBarraDeVida()
{
	printf("🙎🏻‍♂️ | Jogador: nome\n");
	printf("❤️ | ########## - 100/100");
	printf("\n🗡️ | ########## - 100/100");
	printf("\n🛡️ | ########## - 100/100");
}


int sortearVida()
{
	int vida;
	vida = ((rand() % 10) + 1) * 10;

	return vida;
}



int sortearAtq()
{
	int atq;
	atq = ((rand() % 10) + 1) * 10;

	return atq;
}


int sortearDef()
{
	int def;
	def = ((rand() % 5) + 1) * 10;

	return def;
}
