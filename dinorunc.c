#include <stdio.h>

int main () {
	
	int pontuacao = 0;
	float energia = 100;
	int nivel = 1;
	
	
	printf("Dino C  Run\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("Nível Inicial: ", nivel);
	scanf("%d", &nivel);
	printf("Nivel Energia ", energia);
	scanf("%f", &energia);
	system("cls");
	printf("Dino C  Run\n");
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("Dino C\n");
	printf("Nível %d\n", nivel);
	printf("Energia %.1f\n", energia);
	printf("Pontuação %d\n", pontuacao);
	
	printf("Teste 2");
	
	
	return 0;
}