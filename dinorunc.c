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
int sortear_aparicao();
int aparicoes();

int verificarEscolhaJogador();

void aplicarEsquiva(int evento, int corrida);

float atualizarEnergia(float energia, int dano);
float aplicarDano(int escolha, int evento, float energia);

int atualizarPontuacao(int pontuacao, int corrida);

void conclusao(float energia, int pontuacao);

char emojis_aparicoes[12][24] = {
    "🪵",
    "🌵",
    "🕷️",
    "🦅",
    "👻",
    "🕳️",
    "🌊",
    "🐍",
    "🦂",
    "🪨",
    "🔥",
    "☄️"
};

char nomes_aparicoes[12][24] = {
    "Madeira",
    "Cacto",
    "Aranha",
    "Aguia",
    "Fantasma",
    "Buraco",
    "Rio",
    "Cobra",
    "Escorpiao",
    "Pedra",
    "Incendio",
    "Cometa"
};

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
	int sorteado_aparicoes;

	while (energia > 0 && pontuacao < 50)
	{
		limparTela();

		cabecalho(energia, pontuacao);

		corrida = mostrarCorrida();
		
		sorteado_aparicoes = sortear_aparicao();

		evento = aparicoes(sorteado_aparicoes);

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

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// Funções Utilitárias
void limparTela()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// Funções Utilitárias
void dormir(double seg)
{
#ifdef _WIN32
	Sleep((int)(seg * 1000 + 0.5));	// segundos
#else
	usleep((int)(seg * 1000000 + 0.5));	// segundos
#endif
}

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// Funcões ...
void cabecalho(float energia, int pontuacao)
{
	printf("Dino C Run 🦖\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("❤️ Energia: %.1f || 🌟 Pontos: %d\n", energia, pontuacao);
	printf("- - - - - - - - - - - - - - - - -\n");
}

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// Funcões ...
int mostrarCorrida()
{
	int corrida = (rand() % 6) + 5;

	printf("correndo ");

	for (int i = 1; i <= corrida; i++)
	{
		printf(" %dm ", i);
		fflush(stdout);
		dormir(0.4);			// segundos
	}

	printf(" ");
	return corrida;
}

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// funções ...
int sortear_aparicao()
{
	return (rand() % 100) + 1;
}

/* - - - - - - - - - - - - - */
/* - - - - - - - - - - - - - */
// funções ...
int aparicoes(int sorteado_aparicoes)
{

	int chances_aparicoes[12] = {
		12, 23, 34, 44, 53, 62,
		70, 78, 85, 91, 96, 100
	};
	
	int i;

	for (i = 0; i < 12; i++)
	{
		if (sorteado_aparicoes <= chances_aparicoes[i])
		{
			printf("%s", emojis_aparicoes[i]);
			printf("\nNumero Sorteado: %d", sorteado_aparicoes);
			printf("\nChance limite: %d", chances_aparicoes[i]);
			printf("\n%s %s apareceu! (1 - Pular | 2 - Atropelar): ",
				   emojis_aparicoes[i], nomes_aparicoes[i]);

			return i;			// índice do evento
		}
	}

	return -1;
}

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
float atualizarEnergia(float energia, int dano)
{
	energia = energia - dano;
	if (energia < 0)
	{
		energia = 0;
	}
	return energia;
}

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
int atualizarPontuacao(int pontuacao, int corrida)
{
	return pontuacao + corrida;
}

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
int verificarEscolhaJogador()
{
	int escolha;

	scanf("%d", &escolha);

	if (escolha == 1 || escolha == 2)
	{
		return escolha;			// escolhas certas 1 ou 2
	}

	return escolha = 0;
}

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
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

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
float aplicarDano(int escolha, int evento, float energia)
{
	int danos_aparicoes[12] = {
		4, 6, 10, 14, 16, 20,
		22, 24, 28, 30, 35, 50
	};
	
char nomes_aparicoes[12][24] = {
    "tropecou np ",            // 🪵 Tronco
    "se espinhou no ",          // 🌵 Cacto
    "foi mordido pela ",         // 🕷️ Aranha
    "foi atacado pela ",        // 🦅 Aguia
    "se assustou com o ",        // 👻 Fantasma
    "caiu no ",                // 🕳️ Buraco
    "foi arrastado pelo ",     // 🌊 Rio
    "levou o bote da ",        // 🐍 Cobra
    "foi picado por ",         // 🦂 Escorpiao
    "bateu contra o ",           // 🪨 pedregulho
    "foi queimado pelo ",      // 🔥 Incendio
    "foi atingido por um "        // ☄️ Cometa
};


	if (escolha == 2)
	{
		printf("\nFoi atingido  %s %s!!!\n", emojis_aparicoes[evento], nomes_aparicoes[evento]);

		printf("-%d de energia\n\n", danos_aparicoes[evento]);

		energia = atualizarEnergia(energia, danos_aparicoes[evento]);
	}
	if (escolha == 0)
	{
		printf("\nVocê bateu no %s %s!!!\n", emojis_aparicoes[evento], nomes_aparicoes[evento]);

		printf("-%d de energia\n\n", danos_aparicoes[evento] + 5);

		energia = atualizarEnergia(energia, danos_aparicoes[evento] + 5);
	}
	dormir(10);					// segundos
	return energia;
}

	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
void conclusao(float energia, int pontuacao)
{
	if (energia <= 0)
	{
		limparTela();
		cabecalho(energia, pontuacao);
		printf(" \nEnergia esgotada!\n ");
		printf("GAME OVER ☠️\n\n ");
	}
	/* - - - - - - - - - - - - - */
	/* - - - - - - - - - - - - - */
	// Funcões ...
	if (pontuacao >= 50)
	{
		limparTela();
		cabecalho(energia, pontuacao);
		printf("\nAtingiu %d metros\n", pontuacao);
		printf(" VOCÊ GANHOU ! 🏆\n\n ");
	}
}
