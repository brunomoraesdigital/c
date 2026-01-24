#include <stdio.h>
#include <stdlib.h>

int main () {

	int pontuacao = 0;
	float energia = 100;
	int nivel = 1;
	int escolha;

	printf("Dino C Run\n");
	printf("- - - - - - - - - - - - - - - - -\n");

	printf("Nível Inicial: ");
	scanf("%d", &nivel);

	printf("Energia Inicial: ");
	scanf("%f", &energia);

	system("cls");

	printf("Dino C Run\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("Dino C\n");
	printf("Nível %d\n", nivel);
	printf("Energia %.1f\n", energia);
	printf("Pontuação %d\n", pontuacao);

	printf("\nUm cacto apareceu! O que fazer? (1-Pular / 2-Atropelar): ");
	scanf("%d", &escolha);

	if (escolha == 1) {
		printf("Você saltou com perfeição! +10 pontos\n");
		pontuacao = pontuacao + 10;
	}
	else if (escolha == 2) {
		printf("Você bateu no cacto! -20 de energia\n");
		energia = energia - 20;
	}
	else {
		printf("Comando inválido! O Dino ficou confuso\n");
	}

	/* Verificação de GAME OVER */
	if (energia <= 0) {
		printf("\nEnergia esgotada!\n");
		printf("GAME OVER ☠️\n");
		return 0;
	}

	/* Status final */
	printf("\nStatus Atualizado:\n");
	printf("Energia: %.1f\n", energia);
	printf("Pontuação: %d\n", pontuacao);

	return 0;
}