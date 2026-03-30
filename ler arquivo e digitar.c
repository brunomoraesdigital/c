#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define MAX_FRASES 100
#define TAM_FRASE 200

void pausar(int milissegundos)
{
#ifdef _WIN32
	Sleep(milissegundos);
#else
	usleep(milissegundos * 1000);
#endif
}

void digitar(const char *texto, int velocidade)
{
	int tamanho = strlen(texto);

	for (int i = 0; i < tamanho; i++)
	{
		printf("%c", texto[i]);
		fflush(stdout);
		pausar(velocidade);
	}
}

void limpar_tela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void ler_arquivo_e_exibir(const char *nome_arquivo)
{
	char frases[MAX_FRASES][TAM_FRASE];
	int total = 0;

	FILE *arquivo = fopen(nome_arquivo, "r");

	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		return;
	}

	while (fgets(frases[total], TAM_FRASE, arquivo) != NULL)
	{
		frases[total][strcspn(frases[total], "\n")] = '\0';

		total++;

		if (total >= MAX_FRASES)
		{
			printf("Limite de frases atingido!\n");
			break;
		}
	}

	fclose(arquivo);

	limpar_tela();

	printf("=== Exibindo frases do arquivo ===\n\n");

	for (int i = 0; i < total; i++)
	{
		digitar(frases[i], 30);
		printf("\n");
	}
}

int main()
{
	ler_arquivo_e_exibir("texto.txt");
	return 0;
}