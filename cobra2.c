#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif

#define LARGURA 67
#define ALTURA 25
#define MAX_COBRA 1000
#define TOTAL_ITENS 6

typedef struct
{
	int x;
	int y;
} Parte;

typedef struct
{
	int x;
	int y;
	int tipo;
} Item;

Parte cobra[MAX_COBRA];
Item itens[TOTAL_ITENS];

int tamanho = 5;
int direcao_x = 1;
int direcao_y = 0;

int pontos = 0;

int pausado = 0;
int efeito_tempo = 0;

int lento = 0;
int rapido = 0;
int congelado = 0;
int invertido = 0;

int contador_bomba = 0;
int mostrar_festa = 0;			// contador de frames para mostrar
								// "Parabéns!!!"

// Variáveis para o bug
int bug_ativado = 0;
int bug_tempo = 0;
int dir_x_original = 0;
int dir_y_original = 0;

// Destacamentos (bomba)
typedef struct
{
	int x;
	int y;
	time_t fim;
} Detached;

Detached destacamentos[MAX_COBRA];
int num_destacamentos = 0;

// Estados de fim de jogo
int game_over = 0;
int cobra_azul = 0;
time_t game_over_fim = 0;

// ===============================
// Controle de exibição do tamanho com indicador temporário
time_t tempo_ultima_mudanca_tamanho = 0;
int delta_tamanho = 0;			// positivo = ganhou, negativo = perdeu

// ===============================
// Protótipos
void evitar_colisao_apos_bug();
int ocupado(int x, int y);

// ===============================
void dormir(int ms)
{
#ifdef _WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}

// ===============================
#ifndef _WIN32
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}

int getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
#endif

// ===============================
void limpar()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

// ===============================
int ocupado(int x, int y)
{
	for (int i = 0; i < tamanho; i++)
	{
		if (cobra[i].x == x && cobra[i].y == y)
			return 1;
	}
	return 0;
}

// ===============================
void gerar_itens()
{
	int i, j, valido;

	for (i = 0; i < TOTAL_ITENS; i++)
	{
		do
		{
			valido = 1;

			itens[i].x = rand() % (LARGURA - 2) + 1;
			itens[i].y = rand() % (ALTURA - 2) + 1;
			itens[i].tipo = i;

			for (j = 0; j < tamanho; j++)
			{
				if (cobra[j].x == itens[i].x && cobra[j].y == itens[i].y)
				{
					valido = 0;
					break;
				}
			}
		}
		while (!valido);
	}
}

// ===============================
void inicializar()
{
	for (int i = 0; i < tamanho; i++)
	{
		cobra[i].x = 10 - i;
		cobra[i].y = 10;
	}
	gerar_itens();
}

// ===============================
void desenhar()
{
	int x, y, i;

	limpar();

	for (y = 0; y < ALTURA; y++)
	{
		for (x = 0; x < LARGURA; x++)
		{

			if (y == 0 || y == ALTURA - 1 || x == 0 || x == LARGURA - 1)
			{
				printf("#");
				continue;
			}

			int desenhou_item = 0;
			for (i = 0; i < TOTAL_ITENS; i++)
			{
				if (x == itens[i].x && y == itens[i].y)
				{
					switch (itens[i].tipo)
					{
					case 0:
						printf("\033[35m@\033[0m");
						break;
					case 1:
						printf("\033[90m∎\033[0m");
						break;
					case 2:
						printf("\033[33m∎\033[0m");
						break;
					case 3:
						printf("\033[31m∎\033[0m");
						break;
					case 4:
						printf("\033[34mѼ\033[0m");
						break;
					case 5:
						printf("\033[38;5;130m∎\033[0m");
						break;
					}
					desenhou_item = 1;
					break;
				}
			}
			if (desenhou_item)
				continue;

			int desenhado = 0;
			for (i = 0; i < tamanho; i++)
			{
				if (cobra[i].x == x && cobra[i].y == y)
				{
					char *cor;
					if (cobra_azul)
					{
						cor = "\033[34m";
					}
					else if (bug_ativado)
					{
						cor = "\033[90m";
					}
					else if (lento)
					{
						cor = "\033[33m";
					}
					else if (rapido)
					{
						cor = "\033[31m";
					}
					else if (congelado)
					{
						cor = "\033[36m";
					}
					else if (invertido)
					{
						cor = "\033[38;5;130m";
					}
					else
					{
						cor = "\033[32m";
					}
					printf("%s%s\033[0m", cor, i == 0 ? "O" : "o");
					desenhado = 1;
					break;
				}
			}

			if (!desenhado)
			{
				int destacado = 0;
				for (i = 0; i < num_destacamentos; i++)
				{
					if (destacamentos[i].x == x && destacamentos[i].y == y)
					{
						printf("\033[34mo\033[0m");
						destacado = 1;
						break;
					}
				}
				if (!destacado)
					printf(" ");
			}
		}
		printf("\n");
	}

	// Exibe Pontos
	printf("• Pontos: %d\n", pontos);

	// Exibe Tamanho da cobra com indicador temporário de mudança
	printf("• Tamanho: %03d", tamanho);
	time_t agora = time(NULL);
	if (tempo_ultima_mudanca_tamanho != 0 && (agora - tempo_ultima_mudanca_tamanho) < 2)
	{
		if (delta_tamanho > 0)
			printf(" \033[32m+%d\033[0m", delta_tamanho);
		else if (delta_tamanho < 0)
			printf(" \033[31m%d\033[0m", delta_tamanho);	// já negativo
	}
	printf("\n");

	// Linha de estado unificada
	printf("• Estado: ");
	if (game_over)
	{
		printf("💀 Fim de Jogo!\n");
	}
	else if (pausado)
	{
		printf("🧭 Pausado\n");
	}
	else if (mostrar_festa > 0)
	{
		printf("🎉 Parabéns!!!\n");
		mostrar_festa--;
	}
	else
	{
		if (bug_ativado)
		{
			printf("👾 BUGADO (%d)", bug_tempo);
		}
		else if (lento)
		{
			printf("🐌 LENTO (%d)", efeito_tempo);
		}
		else if (rapido)
		{
			printf("🌶️ RÁPIDO (%d)", efeito_tempo);
		}
		else if (congelado)
		{
			printf("💣 EXPLOSÃO (%d)", efeito_tempo);
		}
		else if (invertido)
		{
			printf("🍄 CONFUSÃO (%d)", efeito_tempo);
		}
		else
		{
			printf("🐍 NORMAL");
		}
		printf("\n");
	}

	// Separador e controles (sempre exibidos)
	printf("- - - - - - - - - - - - - - - - - - -\n");
	printf
		("\033[90m• Teclas da esquerda = virar esquerda\n• Teclas da direita = virar direita\n• Tecla espaço = pausar o jogo\033[0m");
	// Move o cursor para bem longe (linha 40, coluna 0)
	printf("\033[40;0H");
	fflush(stdout);
}

// ===============================
void virar_esquerda()
{
	if (direcao_x == 1)
	{
		direcao_x = 0;
		direcao_y = -1;
	}
	else if (direcao_x == -1)
	{
		direcao_x = 0;
		direcao_y = 1;
	}
	else if (direcao_y == 1)
	{
		direcao_x = 1;
		direcao_y = 0;
	}
	else if (direcao_y == -1)
	{
		direcao_x = -1;
		direcao_y = 0;
	}
}

void virar_direita()
{
	if (direcao_x == 1)
	{
		direcao_x = 0;
		direcao_y = 1;
	}
	else if (direcao_x == -1)
	{
		direcao_x = 0;
		direcao_y = -1;
	}
	else if (direcao_y == 1)
	{
		direcao_x = -1;
		direcao_y = 0;
	}
	else if (direcao_y == -1)
	{
		direcao_x = 1;
		direcao_y = 0;
	}
}

// ===============================
// Evita que a cabeça colida com o corpo após mudanças bruscas (bug)
void evitar_colisao_apos_bug()
{
	int prox_x = cobra[0].x + direcao_x;
	int prox_y = cobra[0].y + direcao_y;

	if (ocupado(prox_x, prox_y))
	{
		// Tenta esquerda
		int dx_esq = direcao_x, dy_esq = direcao_y;
		if (direcao_x == 1)
		{
			dx_esq = 0;
			dy_esq = -1;
		}
		else if (direcao_x == -1)
		{
			dx_esq = 0;
			dy_esq = 1;
		}
		else if (direcao_y == 1)
		{
			dx_esq = 1;
			dy_esq = 0;
		}
		else if (direcao_y == -1)
		{
			dx_esq = -1;
			dy_esq = 0;
		}

		int prox_esq_x = cobra[0].x + dx_esq;
		int prox_esq_y = cobra[0].y + dy_esq;

		if (!ocupado(prox_esq_x, prox_esq_y))
		{
			direcao_x = dx_esq;
			direcao_y = dy_esq;
			return;
		}

		// Tenta direita
		int dx_dir = direcao_x, dy_dir = direcao_y;
		if (direcao_x == 1)
		{
			dx_dir = 0;
			dy_dir = 1;
		}
		else if (direcao_x == -1)
		{
			dx_dir = 0;
			dy_dir = -1;
		}
		else if (direcao_y == 1)
		{
			dx_dir = -1;
			dy_dir = 0;
		}
		else if (direcao_y == -1)
		{
			dx_dir = 1;
			dy_dir = 0;
		}

		int prox_dir_x = cobra[0].x + dx_dir;
		int prox_dir_y = cobra[0].y + dy_dir;

		if (!ocupado(prox_dir_x, prox_dir_y))
		{
			direcao_x = dx_dir;
			direcao_y = dy_dir;
			return;
		}
		// Se ambas as direções estiverem bloqueadas, mantém a original
		// (morrerá)
	}
}

// ===============================
void entrada()
{
	if (kbhit())
	{
		char t = getch();

		if (t == ' ')
			pausado = !pausado;

		if (t == 'q' || t == 'w' || t == 'e' || t == 'a' || t == 's' || t == 'd' || t == 'z'
			|| t == 'x' || t == 'c')
		{
			if (invertido)
				virar_direita();
			else
				virar_esquerda();
		}
		else if (t == 'i' || t == 'o' || t == 'p' || t == 'j' || t == 'k' || t == 'l' || t == 'b'
				 || t == 'n' || t == 'm')
		{
			if (invertido)
				virar_esquerda();
			else
				virar_direita();
		}
	}
}

// ===============================
void atualizar()
{
	if (pausado)
		return;
	if (game_over)
		return;

	// Tratamento do efeito bug
	if (bug_ativado)
	{
		bug_tempo--;
		if (bug_tempo <= 0)
		{
			bug_ativado = 0;
			// Inverte a cobra novamente para voltar ao normal
			Parte temp[MAX_COBRA];
			for (int j = 0; j < tamanho; j++)
			{
				temp[j] = cobra[tamanho - 1 - j];
			}
			for (int j = 0; j < tamanho; j++)
			{
				cobra[j] = temp[j];
			}
			// Restaura direção original
			direcao_x = dir_x_original;
			direcao_y = dir_y_original;
			// CORREÇÃO: evita colisão imediata após restaurar
			evitar_colisao_apos_bug();
		}
	}

	if (efeito_tempo > 0)
		efeito_tempo--;
	else
		lento = rapido = congelado = invertido = 0;

	if (congelado)
		return;

	// remove destacamentos expirados
	for (int i = 0; i < num_destacamentos; i++)
	{
		if (time(NULL) >= destacamentos[i].fim)
		{
			destacamentos[i] = destacamentos[num_destacamentos - 1];
			num_destacamentos--;
			i--;
		}
	}

	// move o corpo
	for (int i = tamanho - 1; i > 0; i--)
	{
		cobra[i] = cobra[i - 1];
	}

	// move a cabeça
	cobra[0].x += direcao_x;
	cobra[0].y += direcao_y;

	// teleporte nas bordas
	if (cobra[0].x <= 0)
		cobra[0].x = LARGURA - 2;
	if (cobra[0].x >= LARGURA - 1)
		cobra[0].x = 1;
	if (cobra[0].y <= 0)
		cobra[0].y = ALTURA - 2;
	if (cobra[0].y >= ALTURA - 1)
		cobra[0].y = 1;

	// colisão com o próprio corpo
	for (int i = 1; i < tamanho; i++)
	{
		if (cobra[0].x == cobra[i].x && cobra[0].y == cobra[i].y)
		{
			game_over = 1;
			game_over_fim = time(NULL) + 2;
			cobra_azul = 0;
			return;
		}
	}

	// colisão com itens
	for (int i = 0; i < TOTAL_ITENS; i++)
	{
		if (cobra[0].x == itens[i].x && cobra[0].y == itens[i].y)
		{

			lento = rapido = congelado = invertido = 0;

			switch (itens[i].tipo)
			{
			case 0:			// fruta
				tamanho++;
				pontos++;
				mostrar_festa = 12;	// duração da mensagem "Parabéns!!!"
				// Registra aumento no tamanho
				delta_tamanho = +1;
				tempo_ultima_mudanca_tamanho = time(NULL);
				break;

			case 1:			// BUG
				{
					dir_x_original = direcao_x;
					dir_y_original = direcao_y;

					Parte temp[MAX_COBRA];
					for (int j = 0; j < tamanho; j++)
					{
						temp[j] = cobra[tamanho - 1 - j];
					}
					for (int j = 0; j < tamanho; j++)
					{
						cobra[j] = temp[j];
					}
					direcao_x = -direcao_x;
					direcao_y = -direcao_y;

					// CORREÇÃO: evita colisão imediata após ativar bug
					evitar_colisao_apos_bug();

					bug_ativado = 1;
					bug_tempo = 50;
				}
				break;

			case 2:
				lento = 1;
				efeito_tempo = 50;
				break;
			case 3:
				rapido = 1;
				efeito_tempo = 50;
				break;

			case 4:			// bomba
				{
					contador_bomba++;
					int dano = 1 << (contador_bomba - 1);
					if (dano >= tamanho)
					{
						game_over = 1;
						game_over_fim = time(NULL) + 2;
						cobra_azul = 1;
					}
					else
					{
						for (int d = 0; d < dano; d++)
						{
							int idx = tamanho - 1 - d;
							if (idx >= 0)
							{
								destacamentos[num_destacamentos].x = cobra[idx].x;
								destacamentos[num_destacamentos].y = cobra[idx].y;
								destacamentos[num_destacamentos].fim = time(NULL) + 2;
								num_destacamentos++;
							}
						}
						tamanho -= dano;
						if (tamanho < 1)
							tamanho = 1;
						// Registra perda de tamanho
						delta_tamanho = -dano;
						tempo_ultima_mudanca_tamanho = time(NULL);
					}
				}
				break;

			case 5:
				invertido = 1;
				efeito_tempo = 50;
				break;
			}

			gerar_itens();
			break;
		}
	}
}

// ===============================
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "pt_BR.UTF-8");
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	inicializar();
	// Esconde o cursor para evitar piscar incômodo
	printf("\033[?25l");

	while (1)
	{
		entrada();
		atualizar();
		desenhar();

		if (game_over && time(NULL) >= game_over_fim)
		{
			break;
		}

		int velocidade = 80;
		if (lento)
			velocidade = 160;
		if (rapido)
			velocidade = 40;

		dormir(velocidade);
	}
	// Restaura o cursor ao sair
	printf("\033[?25h");
	return 0;
}
