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
  
// ===============================  
// Prototipos de Funcoes Utilitarias  
// ===============================  
void limparTela();  
void dormir(double seg);  
  
// ===============================  
// Prototipos de Funcoes Principais do Jogo  
// ===============================  
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

// ===============================  
// Arrays de Aparicoes  
// ===============================  
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
	"Tronco",  
	"Cacto",  
	"Aranha",  
	"Águia",  
	"Fantasma",  
	"Buraco",  
	"Rio",  
	"Cobra",  
	"Escorpião",  
	"Pedra",  
	"Incêndio",  
	"Cometa"  
};  

// ===============================  
// Funcao Principal  
// ===============================  
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

// ===============================  
// Funcoes Utilitarias  
// ===============================  
void limparTela()  
{  
#ifdef _WIN32  
	system("cls");  
#else  
	system("clear");  
#endif  
}  

void dormir(double seg)  
{  
#ifdef _WIN32  
	Sleep((int)(seg * 1000 + 0.5));  
#else  
	usleep((int)(seg * 1000000 + 0.5));  
#endif  
}  

// ===============================  
// Funcoes de Interface  
// ===============================  
void cabecalho(float energia, int pontuacao)  
{  
	printf("Dino C Run 🦖\n");  
	printf("==============================\n");  
	printf("❤️ Energia: %.1f || 🌟 Pontos: %d\n", energia, pontuacao);  
	printf("==============================\n");  
}  

// ===============================  
// Logica da Corrida  
// ===============================  
int mostrarCorrida()  
{  
	int corrida = (rand() % 6) + 5;  

	printf("Correndo: ");  

	for (int i = 1; i <= corrida; i++)  
	{  
		printf("%dm ", i);  
		fflush(stdout);  
		dormir(0.4);  
	}  

	printf(" ");  
	return corrida;  
}  

// ===============================  
// Sorteio e Aparicoes  
// ===============================  
int sortear_aparicao()  
{  
	return (rand() % 100) + 1;  
}  

int aparicoes(int sorteado_aparicoes)  
{  
	int chances_aparicoes[12] = {  
		12, 23, 34, 44, 53, 62,  
		70, 78, 85, 91, 96, 100  
	};  

	char artigos[12][4] = {  
		"Um",  "Um",  "Uma",  "Uma",  "Um",  "Um",  
		"Um",  "Uma",  "Um",  "Uma",  "Um",  "Um"  
	};  

	for (int i = 0; i < 12; i++)  
	{  
		if (sorteado_aparicoes <= chances_aparicoes[i])  
		{  
			printf("%s\n", emojis_aparicoes[i]);  
			printf("\n%s %s %s apareceu! (1 - Pular | 2 - Atropelar): ", artigos[i],  
				   emojis_aparicoes[i], nomes_aparicoes[i]);  
			return i;  
		}  
	}  
	return -1;  
}  

// ===============================  
// Atualizacao de Energia e Pontuacao  
// ===============================  
float atualizarEnergia(float energia, int dano)  
{  
	energia -= dano;  
	if (energia < 0) energia = 0;  
	return energia;  
}  

int atualizarPontuacao(int pontuacao, int corrida)  
{  
	return pontuacao + corrida;  
}  

// ===============================  
// Entrada do Jogador  
// ===============================  
int verificarEscolhaJogador()  
{  
	int escolha;  
	scanf("%d", &escolha);  

	if (escolha == 1 || escolha == 2)  
		return escolha;  

	return 0;  
}  

// ===============================  
// Acao de Esquiva  
// ===============================  
void aplicarEsquiva(int evento, int corrida)  
{  
	if (evento == 0)  
		printf("\nO Dino pulou com perfeição!!\n");  
	else  
		printf("\nO Dino abaixou com perfeição!!\n");  

	printf("O Dino ganhou %d pontos!!!\n\n", corrida);  
	dormir(3);  
}  

// ===============================  
// Aplicacao de Dano  
// ===============================  
float aplicarDano(int escolha, int evento, float energia)  
{  
	int danos_aparicoes[12] = { 4, 6, 10, 14, 16, 20, 22, 24, 28, 30, 35, 50 };  

	char consequencias_aparicoes[12][24] = {  
		"tropeçou no", "se espinhou no", "foi mordido pela",  
		"foi atacado pela", "se assustou com o", "caiu no",  
		"foi arrastado pelo", "levou o bote da", "foi picado pelo",  
		"bateu contra o", "foi queimado pelo", "foi atingido por um"  
	};  

	char falhou[12][64] = {  
		"O Dino C se distraiu com uma borboleta e",  
		"O Dino C piscou no momento errado e",  
		"O Dino C cochilou correndo e",  
		"O Dino C se esqueceu de desviar e",  
		"O Dino C se confundiu entre subir ou descer e",  
		"O Dino C sonhou acordado e",  
		"O Dino C desviou a atenção para uma dinossaurinha e",  
		"O Dino C espirrou por cócegas de uma abelhinha e",  
		"O Dino C se atrapalhou com as pernas e",  
		"O Dino C lembrou de algo engraçado e",  
		"O Dino C admirou a paisagem e",  
		"O Dino C hesitou se conseguiria e"  
	};  

	if (escolha == 2)  
	{  
		printf("\nO Dino C %s %s %s!!!\n", consequencias_aparicoes[evento], emojis_aparicoes[evento], nomes_aparicoes[evento]);  
		printf("Perdeu %d de energia\n\n", danos_aparicoes[evento]);  
		energia = atualizarEnergia(energia, danos_aparicoes[evento]);  
	}  

	if (escolha == 0)  
	{  
		int j = rand() % 12;  
		printf("\n%s %s %s %s!!!\n", falhou[j], consequencias_aparicoes[evento], emojis_aparicoes[evento], nomes_aparicoes[evento]);  
		printf("Perdeu %d de energia\n\n", danos_aparicoes[evento] + 5);  
		energia = atualizarEnergia(energia, danos_aparicoes[evento] + 5);  
	}  

	dormir(4);  
	return energia;  
}  

// ===============================  
// Finalizacao do Jogo  
// ===============================  
void conclusao(float energia, int pontuacao)  
{  
	if (energia <= 0)  
	{  
		limparTela();  
		cabecalho(energia, pontuacao);  
		printf("\nEnergia esgotada!\nGAME OVER ☠️\n\n");  
	}  

	if (pontuacao >= 50)  
	{  
		limparTela();  
		cabecalho(energia, pontuacao);  
		printf("\nAtingiu %d metros\nVOCÊ GANHOU! 🏆\n\n", pontuacao);  
	}  
}