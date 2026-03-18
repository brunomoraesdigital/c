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

char coracao[] = "❤️";
char espada[] = "🗡️";
char escudo[] = "🛡️";
char barraCheia[] = "█";
char barraVazia[] = "░";

void exibirBarraDeVida(int atq, int def, int vida)
{
	printf(" | ");
	printf(" - %d/100", vida);


}


int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	srand(time(NULL));

	exibirBarraDeVida(10, 10, 10);

	return 0;
}
