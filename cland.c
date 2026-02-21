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
double seg = 3;

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

#ifdef _WIN32
    system("cls");
    printf("CRONICAS DE C-LAND 🏰✨\n\n");  
#else
    system("clear");
    printf("CRONICAS DE C-LAND 🏰✨\n\n");  
#endif
 


	printf("Recepcionista:\n");
	printf("--------------------------------\n");
	printf("Boas-vindas!! 🤝\n");
	printf("Para iniciar seu registro\n");
	printf("na guilda dos aventureiros,\n");
	printf("preencha este formulario. 📝\n");
	printf("--------------------------------\n\n");
#ifdef _WIN32
    Sleep((int)(seg * 1000 + 0.5));
#else
    usleep((int)(seg * 1000000 + 0.5));
#endif
#ifdef _WIN32
    system("cls");
    printf("CRONICAS DE C-LAND 🏰✨\n\n");  
#else
    system("clear");
    printf("CRONICAS DE C-LAND 🏰✨\n\n");  
#endif
	float peso = 0;
	float altura = 0;
	int idade = 0;
	char nome[25] = { "" };
	char classe[25] = { "Mago" };
	char rank = 'F';
	int nivel = 1;

	int forca = 1;
	int destreza = 1;
	int inteligencia = 1;
	int sorte = 1;
	int agilidade = 1;
	int vitalidade = 1;

	int pontosDeAtributos = 3;

	float ataqueMagico = 0;
	float ataqueFisico = 0;
	float ataqueDistancia = 0;

	int classeMagica = 1;
	int classeFisica = 0;
	int classeDistancia = 0;

	char decisaoAtributos = 'n';
	int resetPontosDeAtributos = 0;
	int resetAtributoInteligencia = 0;
	int resetAtributoDestreza = 0;

	printf("???::\n");
	printf("--------------------------------\n");
	printf("Hmm, vejamos... 👀\n");

	printf("O meu nome? ");
	scanf("%24s", nome);

	printf("A minha classe? %s\n", classe);

	printf("A minha idade? ");
	scanf("%d", &idade);

	printf("A minha altura? ");
	scanf("%f", &altura);

	printf("O meu peso? ");
	scanf("%f", &peso);

	printf("Terminei, aqui esta o formulario. 📄\n");
	printf("--------------------------------\n\n");

	if ((altura / 100) > 1)
	{
		altura /= 100;
	}

	printf("Recepcionista:\n");
	printf("--------------------------------\n");
	printf("Vamos ver... 👀\n");
	printf("Esta tudo certo.\n");
	printf("Aqui esta o seu registro. 🪪\n");
	printf("--------------------------------\n\n");

	printf("Registro:\n");
	printf("--------------------------------\n");
	printf("Aventureiro %s 🙎🏻\n", nome);
	printf("Classe: %s\n", classe);
	printf("Rank %c\n", rank);
	printf("Idade %d anos\n", idade);
	printf("Altura %.2f m\n", altura);
	printf("Peso %.2f kg\n", peso);

	printf("\nAtributos:\n");
	printf("Vit: %d\tAgi: %d\n", vitalidade, agilidade);
	printf("For: %d\tInt: %d\n", forca, inteligencia);
	printf("Des: %d\tSor: %d\n", destreza, sorte);

	printf("Ataque Fisico: %.2f\n", ataqueFisico);
	printf("Ataque Magico: %.2f\n", ataqueMagico);
	printf("Pontos de Atributos: %d\n", pontosDeAtributos);
	printf("--------------------------------\n\n");

	printf("Recepcionista:\n");
	printf("--------------------------------\n");
	printf("Voce pode entrar agora. 🚪✨\n");
	printf("--------------------------------\n\n");

	printf("Eldrin:\n");
	printf("--------------------------------\n");
	printf("Ja era hora... entao voce finalmente apareceu. 😤\n");
	printf("Esta pronto para o que nos espera? ⚔️\n");
	printf("Errr... qual e mesmo o seu nome? 🤔\n");
	printf("--------------------------------\n\n");

	printf("%s:\n", nome);
	printf("--------------------------------\n");
	printf("Meu nome e %s, senhor.\n", nome);
	printf("Sim, estou preparado. 💪🔥\n");
	printf("--------------------------------\n\n");

	printf("Eldrin:\n");
	printf("--------------------------------\n");
	printf("Ah... certo, agora me recordei. 😌\n");
	printf("Perfeito, %s.\n", nome);
	printf("Agora o grupo esta completo. 🛡️⚔️\n");
	printf("--------------------------------\n\n");

	printf("Eldrin:\n");
	printf("--------------------------------\n");
	printf("%s antes de continuarmos\n", nome);
	printf("Voce deve distribuir seus pontos de atributos. 🎯\n");
	printf("Faca isso usando seu Registro\n");
	printf("--------------------------------\n");

	printf("Registro\n");
	printf("--------------------------------\n");
	printf("Distribuir pontos de atributos? (s | n): ");
	scanf(" %c", &decisaoAtributos);
	printf("--------------------------------\n");

	while (decisaoAtributos == 's')
	{
		printf("Registro\n");
		printf("--------------------------------\n");
		printf("Pontos de atributos restantes: %d\n", pontosDeAtributos);

		printf("Aumentar Inteligencia? (s | n): ");
		scanf(" %c", &decisaoAtributos);
		if (decisaoAtributos == 's')
		{
			pontosDeAtributos--; //0
			inteligencia++;
		}

		printf("Pontos de atributos restantes: %d\n", pontosDeAtributos);

		printf("Aumentar Destreza? (s | n): ");
		scanf(" %c", &decisaoAtributos);
		if (decisaoAtributos == 's')
		{
			pontosDeAtributos--; //-1
			destreza++;
			printf("PA -> %d\n", pontosDeAtributos);
			printf("RPA-> %d\n", resetPontosDeAtributos);
		}
		printf("--------------------------------\n");
		
		printf("Registro\n");
		printf("--------------------------------\n");
		if (pontosDeAtributos > 0)
		{
			resetPontosDeAtributos = pontosDeAtributos; //1
			resetAtributoInteligencia = inteligencia;
			resetAtributoDestreza = destreza;

			printf("Continuar distribuindo? (s | n): ");
			scanf(" %c", &decisaoAtributos);
			printf("--------------------------------\n");
		}
		else if (pontosDeAtributos == 0)
		{
			printf("Nao ha mais pontos para distribuir.\n");
			decisaoAtributos = 'n';
			printf("--------------------------------\n");
		}
		else
		{
			pontosDeAtributos = resetPontosDeAtributos;
			inteligencia = resetAtributoInteligencia;
			destreza = resetAtributoDestreza;

			printf("Pontos insuficientes, distribuicao desfeita.\n");
			printf("Continuar distribuindo? (s | n): ");
			scanf(" %c", &decisaoAtributos);
			printf("--------------------------------\n");
		}
	}

	if (pontosDeAtributos == 0)
	{
		printf("Eldrin: Voce conhece bem seus limites!\n");

		if (classeMagica == 1)
			ataqueMagico = (inteligencia * 3) + (destreza / 2.0) + sorte;
		else if (classeFisica == 1)
			ataqueFisico = (forca * 2) + (destreza / 2.0) + sorte;
		else if (classeDistancia == 1)
			ataqueDistancia = (destreza * 3) + (inteligencia / 2.0) + sorte;
	}
	else
	{
		printf("Eldrin: Voce ainda tem %d pontos sobrando.\n", pontosDeAtributos);
	}

	printf("\nRegistro Final:\n");
	printf("--------------------------------\n");
	printf("Aventureiro %s 🙎🏻\n", nome);
	printf("Classe: %s\n", classe);
	printf("Rank %c\n", rank);
	printf("Idade %d anos\n", idade);
	printf("Altura %.2f m\n", altura);
	printf("Peso %.2f kg\n", peso);

	printf("\nAtributos:\n");
	printf("Vit: %d\tAgi: %d\n", vitalidade, agilidade);
	printf("For: %d\tInt: %d\n", forca, inteligencia);
	printf("Des: %d\tSor: %d\n", destreza, sorte);

	printf("Ataque Fisico: %.2f\n", ataqueFisico);
	printf("Ataque Magico: %.2f\n", ataqueMagico);
	printf("Pontos de Atributos restantes: %d\n", pontosDeAtributos);
	printf("--------------------------------\n\n");

	return 0;
}
