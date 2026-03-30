#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

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

void ler_e_exibir_direto(const char *nome_arquivo)
{
	FILE *arquivo = fopen(nome_arquivo, "r");

	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!\n");
		return;
	}

	char linha[TAM_FRASE];

	limpar_tela();

	printf("=== Exibindo direto do arquivo ===\n\n");

	while (fgets(linha, TAM_FRASE, arquivo) != NULL)
	{
		linha[strcspn(linha, "\n")] = '\0';

		digitar(linha, 30);
		printf("\n");

		// Espera ENTER (estilo jogo)
		printf("\nPressione ENTER para continuar...");
		getchar();
	}

	fclose(arquivo);
}

int main()
{
	ler_e_exibir_direto("texto.txt");
	return 0;
}