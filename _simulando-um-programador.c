#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define LARGURA 67
#define ALTURA 25

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
	for (int i = 0; i < strlen(texto); i++)
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

float limitar(float valor, float max)
{
	if (valor > max)
		return max;
	if (valor < -max)
		return -max;
	return valor;
}

int main()
{
	for (int i = 0; i < 6; i++)
	{
		pausar(500);
#ifdef _WIN32
		digitar("", 40);
		system("cls");
#else
		digitar("", 40);
		system("clear");
#endif
	}
	// Parte 1: digitação do código (simulação)
	pausar(500);
	digitar("#include <stdio.h>\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("#ifdef _WIN32\n", 40);
	pausar(500);
	digitar("#include <windows.h>\n", 40);
	pausar(500);
	digitar("#else\n", 40);
	pausar(500);
	digitar("#include <unistd.h>\n", 40);
	pausar(500);
	digitar("#endif\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("#define LARGURA 67\n", 40);
	pausar(500);
	digitar("#define ALTURA 25\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("void pausar(int ms) {\n", 40);
	pausar(500);
	digitar("#ifdef _WIN32\n", 40);
	pausar(500);
	digitar("    Sleep(ms);\n", 40);
	pausar(500);
	digitar("#else\n", 40);
	pausar(500);
	digitar("    usleep(ms * 1000);\n", 40);
	pausar(500);
	digitar("#endif\n", 40);
	pausar(500);
	digitar("}\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("void limpar_tela() {\n", 40);
	pausar(500);
	digitar("#ifdef _WIN32\n", 40);
	pausar(500);
	digitar("    system(\"cls\");\n", 40);
	pausar(500);
	digitar("#else\n", 40);
	pausar(500);
	digitar("    system(\"clear\");\n", 40);
	pausar(500);
	digitar("#endif\n", 40);
	pausar(500);
	digitar("}\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("float limitar(float valor, float max) {\n", 40);
	pausar(500);
	digitar("    if (valor > max) return max;\n", 40);
	pausar(500);
	digitar("    if (valor < -max) return -max;\n", 40);
	pausar(500);
	digitar("    return valor;\n", 40);
	pausar(500);
	digitar("}\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("int main() {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("#ifdef _WIN32\n", 40);
	pausar(500);
	digitar("    SetConsoleOutputCP(CP_UTF8);\n", 40);
	pausar(500);
	digitar("#endif\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    float x = 20, y = 5;\n", 40);
	pausar(500);
	digitar("    float vx = 1.2, vy = 0;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    float vx_inicial = 1.2;\n", 40);
	pausar(500);
	digitar("    float vy_inicial = -2.5;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    float gravidade = 0.2;\n", 40);
	pausar(500);
	digitar("    float quique = 0.85;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    int vida = 10;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    int raquete_largura = 9;\n", 40);
	pausar(500);
	digitar("    int raquete_x = LARGURA / 2 - raquete_largura / 2;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    int rastro[ALTURA][LARGURA];\n", 40);
	pausar(500);
	digitar("    int i, j;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    for (i = 0; i < ALTURA; i++)\n", 40);
	pausar(500);
	digitar("        for (j = 0; j < LARGURA; j++)\n", 40);
	pausar(500);
	digitar("            rastro[i][j] = 0;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    while (1) {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // IA da raquete\n", 40);
	pausar(500);
	digitar("        int centro = raquete_x + raquete_largura / 2;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        if (x > centro) raquete_x++;\n", 40);
	pausar(500);
	digitar("        else if (x < centro) raquete_x--;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        if (raquete_x < 0) raquete_x = 0;\n", 40);
	pausar(500);
	digitar("        if (raquete_x + raquete_largura >= LARGURA)\n", 40);
	pausar(500);
	digitar("            raquete_x = LARGURA - raquete_largura;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // física\n", 40);
	pausar(500);
	digitar("        vy += gravidade;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        float prox_x = x + vx;\n", 40);
	pausar(500);
	digitar("        float prox_y = y + vy;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // colisão lateral\n", 40);
	pausar(500);
	digitar("        if (prox_x < 0 || prox_x >= LARGURA) {\n", 40);
	pausar(500);
	digitar("            vx = -vx;\n", 40);
	pausar(500);
	digitar("            prox_x = x + vx;\n", 40);
	pausar(500);
	digitar("        }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // colisão com raquete\n", 40);
	pausar(500);
	digitar("        if (vy > 0 && prox_y >= ALTURA - 2) {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("            if ((int)prox_x >= raquete_x &&\n", 40);
	pausar(500);
	digitar("                (int)prox_x <= raquete_x + raquete_largura) {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                y = ALTURA - 3;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                vy = vy_inicial;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar
		("                float impacto = (prox_x - (raquete_x + raquete_largura / 2)) / 4.0;\n",
		 40);
	pausar(500);
	digitar("                vx += impacto;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                vx = limitar(vx, vx_inicial);\n", 40);
	pausar(500);
	digitar("                vy = limitar(vy, -vy_inicial);\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                vida++; // ganha vida\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("            } else if (prox_y >= ALTURA - 1) {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                y = ALTURA - 1;\n", 40);
	pausar(500);
	digitar("                vy = -vy * quique;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                vida--; // perde vida\n", 40);
	pausar(500);
	digitar("            }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        } else {\n", 40);
	pausar(500);
	digitar("            x = prox_x;\n", 40);
	pausar(500);
	digitar("            y = prox_y;\n", 40);
	pausar(500);
	digitar("        }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // fim de jogo\n", 40);
	pausar(500);
	digitar("        if (vida <= 0) {\n", 40);
	pausar(500);
	digitar("            limpar_tela();\n", 40);
	pausar(500);
	digitar("            printf(\"\\n\\n      FIM DE JOGO\\n\");\n", 40);
	pausar(500);
	digitar("            printf(\"Vida chegou a zero\\n\");\n", 40);
	pausar(500);
	digitar("            break;\n", 40);
	pausar(500);
	digitar("        }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // rastro\n", 40);
	pausar(500);
	digitar("        int ix = (int)x;\n", 40);
	pausar(500);
	digitar("        int iy = (int)y;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)\n", 40);
	pausar(500);
	digitar("            rastro[iy][ix] = 5;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        for (i = 0; i < ALTURA; i++)\n", 40);
	pausar(500);
	digitar("            for (j = 0; j < LARGURA; j++)\n", 40);
	pausar(500);
	digitar("                if (rastro[i][j] > 0)\n", 40);
	pausar(500);
	digitar("                    rastro[i][j]--;\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        limpar_tela();\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        // desenha\n", 40);
	pausar(500);
	digitar("        for (i = 0; i < ALTURA; i++) {\n", 40);
	pausar(500);
	digitar("            for (j = 0; j < LARGURA; j++) {\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("                if ((int)x == j && (int)y == i) {\n", 40);
	pausar(500);
	digitar("                    printf(\"O\");\n", 40);
	pausar(500);
	digitar("                }\n", 40);
	pausar(500);
	digitar("                else if (i == ALTURA - 1 &&\n", 40);
	pausar(500);
	digitar("                         j >= raquete_x &&\n", 40);
	pausar(500);
	digitar("                         j <= raquete_x + raquete_largura) {\n", 40);
	pausar(500);
	digitar("                    printf(\"=\");\n", 40);
	pausar(500);
	digitar("                }\n", 40);
	pausar(500);
	digitar("                else {\n", 40);
	pausar(500);
	digitar("                    if (rastro[i][j] >= 4) printf(\"@\");\n", 40);
	pausar(500);
	digitar("                    else if (rastro[i][j] >= 3) printf(\"#\");\n", 40);
	pausar(500);
	digitar("                    else if (rastro[i][j] >= 2) printf(\"*\");\n", 40);
	pausar(500);
	digitar("                    else if (rastro[i][j] >= 1) printf(\".\");\n", 40);
	pausar(500);
	digitar("                    else printf(\" \");\n", 40);
	pausar(500);
	digitar("                }\n", 40);
	pausar(500);
	digitar("            }\n", 40);
	pausar(500);
	digitar("            printf(\"\\n\");\n", 40);
	pausar(500);
	digitar("        }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        printf(\"Vida: %d\\n\", vida);\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("        pausar(40);\n", 40);
	pausar(500);
	digitar("    }\n", 40);
	pausar(500);
	digitar("\n", 40);
	pausar(500);
	digitar("    return 0;\n", 40);
	pausar(500);
	digitar("}\n", 40);

	// Mensagens finais da simulação
	digitar("Iniciando sistema...\n", 40);
	pausar(500);
	digitar("Conectando ao servidor...\n", 40);
	pausar(500);
	digitar("Verificando credenciais...\n\n", 40);
	pausar(500);

	// Barra de carregamento corrigida
	digitar("Carregando: [", 40);
	for (int i = 0; i <= 50; i++)
	{
		printf("#");
		fflush(stdout);
		pausar(40);
	}
	printf("] 100%%\n\n");

	pausar(500);
	digitar(">>> ACESSO LIBERADO <<<\n", 30);
	pausar(500);

	// ------------------------------------------------------------
	// Parte 2: execução do jogo (código real)
	// ------------------------------------------------------------
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	float x = 20, y = 5;
	float vx = 1.2, vy = 0;

	float vx_inicial = 1.2;
	float vy_inicial = -2.5;

	float gravidade = 0.2;
	float quique = 0.85;

	int vida = 10;

	int raquete_largura = 9;
	int raquete_x = LARGURA / 2 - raquete_largura / 2;

	int rastro[ALTURA][LARGURA];
	int i, j;

	for (i = 0; i < ALTURA; i++)
		for (j = 0; j < LARGURA; j++)
			rastro[i][j] = 0;

	while (1)
	{
		// IA da raquete
		int centro = raquete_x + raquete_largura / 2;

		if (x > centro)
			raquete_x++;
		else if (x < centro)
			raquete_x--;

		if (raquete_x < 0)
			raquete_x = 0;
		if (raquete_x + raquete_largura >= LARGURA)
			raquete_x = LARGURA - raquete_largura;

		// física
		vy += gravidade;

		float prox_x = x + vx;
		float prox_y = y + vy;

		// colisão lateral
		if (prox_x < 0 || prox_x >= LARGURA)
		{
			vx = -vx;
			prox_x = x + vx;
		}

		// colisão com raquete
		if (vy > 0 && prox_y >= ALTURA - 2)
		{
			if ((int)prox_x >= raquete_x && (int)prox_x <= raquete_x + raquete_largura)
			{

				y = ALTURA - 3;

				vy = vy_inicial;

				float impacto = (prox_x - (raquete_x + raquete_largura / 2)) / 4.0;
				vx += impacto;

				vx = limitar(vx, vx_inicial);
				vy = limitar(vy, -vy_inicial);

				vida++;			// ganha vida

			}
			else if (prox_y >= ALTURA - 1)
			{
				y = ALTURA - 1;
				vy = -vy * quique;

				vida--;			// perde vida
			}
		}
		else
		{
			x = prox_x;
			y = prox_y;
		}

		// fim de jogo
		if (vida <= 0)
		{
			limpar_tela();
			printf("\n\n      FIM DE JOGO\n");
			printf("Vida chegou a zero\n");
			break;
		}

		// rastro
		int ix = (int)x;
		int iy = (int)y;

		if (ix >= 0 && ix < LARGURA && iy >= 0 && iy < ALTURA)
			rastro[iy][ix] = 5;

		for (i = 0; i < ALTURA; i++)
			for (j = 0; j < LARGURA; j++)
				if (rastro[i][j] > 0)
					rastro[i][j]--;

		limpar_tela();

		// desenha
		for (i = 0; i < ALTURA; i++)
		{
			for (j = 0; j < LARGURA; j++)
			{
				if ((int)x == j && (int)y == i)
				{
					printf("O");
				}
				else if (i == ALTURA - 1 && j >= raquete_x && j <= raquete_x + raquete_largura)
				{
					printf("=");
				}
				else
				{
					if (rastro[i][j] >= 4)
						printf("@");
					else if (rastro[i][j] >= 3)
						printf("#");
					else if (rastro[i][j] >= 2)
						printf("*");
					else if (rastro[i][j] >= 1)
						printf(".");
					else
						printf(" ");
				}
			}
			printf("\n");
		}

		printf("Vida: %d\n", vida);

		pausar(40);
	}

	return 0;
}
