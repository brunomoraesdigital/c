#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
// Para Windows (Sleep)
#include <windows.h>
#else
// Para Linux/Android (usleep e sleep)
#include <unistd.h>
#endif

// Funções Utilitárias
void limparTela();
void dormir(double seg);

void cabecalho(float energia, int pontuacao);
int mostrarCorrida();
int aparicoes(int evento);

int verificarEscolhaJogador();

void aplicarEsquiva(int evento, int corrida);

float atualizarEnergia(float energia, int dano);
float aplicarDano(int escolha, int evento, float energia);

int atualizarPontuacao(int pontuacao, int corrida);

void conclusao(float energia, int pontuacao);

int main()
{

#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	srand(time(NULL));

	int pontuacao = 0;
	float energia = 100;
	int escolha;
	int corrida = 0;
	int evento = 0;

	while (energia > 0 && pontuacao < 50)
	{
		limparTela();

		cabecalho(energia, pontuacao);

		corrida = mostrarCorrida();

		evento = aparicoes(evento);

		escolha = verificarEscolhaJogador();

		if (escolha == 1)
		{
			aplicarEsquiva(evento, corrida);
			pontuacao = atualizarPontuacao(pontuacao, corrida);
		}
		else
		{
			energia = aplicarDano(escolha, evento, energia);
		}

		conclusao(energia, pontuacao);
	}
	return 0;
}

// Funções Utilitárias
void limparTela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
// Funções Utilitárias
void dormir(double seg)
{
#ifdef _WIN32
	Sleep((int)(seg * 1000 + 0.5)); // segundos
#else
	usleep((int)(seg * 1000000 + 0.5)); // segundos
#endif
}

void cabecalho(float energia, int pontuacao)
{
	printf("Dino C Run 🦖\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("❤️ Energia: %.1f || 🌟 Pontos: %d\n", energia, pontuacao);
	printf("- - - - - - - - - - - - - - - - -\n");
}

int mostrarCorrida()
{
	int corrida = (rand() % 6) + 5;

	printf("correndo ");

	for (int i = 1; i <= corrida; i++)
	{
		printf(" %dm ", i);
		fflush(stdout);
		dormir(0.4); // segundos
	}

	printf(" ");
	return corrida;
}

int aparicoes(int evento)
{
	evento = rand() % 2;

	if (evento == 0)
	{
		printf("🌵 \n");
		printf(" \n 🌵 Um cacto apareceu! (1 - Pular | 2 - Atropelar): ");
	}
	else
	{
		printf("🦅 \n");
		printf(" \n 🦅 Um abutre apareceu! (1 - Abaixar | 2 - Colidir): ");
	}

	return evento;
}

float atualizarEnergia(float energia, int dano)
{
	energia = energia - dano;
	if (energia < 0)
	{
		energia = 0;
	}
	return energia;
}

int atualizarPontuacao(int pontuacao, int corrida)
{
	return pontuacao + corrida;
}

int verificarEscolhaJogador()
{
	int escolha;

	scanf("%d", &escolha);

	if (escolha == 1 || escolha == 2)
	{
		return escolha; // escolhas certas 1 ou 2
	}

	return escolha = 0;
}

void aplicarEsquiva(int evento, int corrida)
{
	if (evento == 0)
	{
		printf("\nVocê pulou com perfeição!!\n");
		printf("Voce ganhou %d pontos!!!\n\n", corrida);
	}
	else
	{
		printf("\nVocê abaixou com perfeição!!\n");
		printf("Voce ganhou %d pontos!!!\n\n", corrida);
	}
	dormir(3);
}

float aplicarDano(int escolha, int evento, float energia)
{
	if (escolha == 2)
	{
		if (evento == 0)
		{
			printf(" Você bateu no cacto! \n ");
			printf(" -10 de energia \n\n ");
			energia = atualizarEnergia(energia, 10);
		}
		else
		{
			printf(" Você bateu no abutre! \n ");
			printf(" -20 de energia \n\n ");
			energia = atualizarEnergia(energia, 20);
		}
	}
	if (escolha == 0)
	{
		if (evento == 0)
		{
			printf(" Comando inválido! \n ");
			printf(" O Dino ficou confuso e atropelou o cacto! \n ");
			printf(" -15 de energia \n\n ");
			energia = atualizarEnergia(energia, 15);
		}
		else
		{
			printf(" Comando inválido ! \n ");
			printf(" O Dino ficou confuso e colidiu no abutre ! \n ");
			printf(" - 25 de energia \n\n ");
			energia = atualizarEnergia(energia, 25);
		}
	}
	dormir(3); // segundos
	return energia;
}

void conclusao(float energia, int pontuacao)
{
	if (energia <= 0)
	{
		limparTela();
		cabecalho(energia, pontuacao);
		printf(" \nEnergia esgotada!\n ");
		printf("GAME OVER ☠️\n\n ");
	}

	if (pontuacao >= 50)
	{
		limparTela();
		cabecalho(energia, pontuacao);
		printf("\nAtingiu %d metros\n", pontuacao);
		printf(" VOCÊ GANHOU ! 🏆\n\n ");
	}
}
