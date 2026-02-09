#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    printf("CRÔNICAS DE C-LAND 🏰✨\n\n");

    printf("Recepcionista:\n");
    printf("--------------------------------\n");
    printf("Boas-vindas!! 🤝\n");
    printf("Para iniciar seu registro\n");
    printf("na guilda dos aventureiros,\n");
    printf("preencha este formulário. 📝\n");
    printf("--------------------------------\n\n");

    float peso = 0;
    float altura = 0;
    int idade = 0;
    char nome[25];
    char classe[25] = {"Mago"};
    char rank = 'F';

    int forca = 1;
    int destreza = 1;
    int inteligencia = 1;
    int sorte = 1;
    int agilidade = 1;
    int vitalidade = 1;

    int pontosDeAtributos = 10;

    float ataqueMagico;
    float ataqueFisico;
    float ataqueDistancia;

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
    printf("Terminei, aqui está o formulário. 📄\n");
    printf("--------------------------------\n\n");

    printf("Recepcionista:\n");
    printf("--------------------------------\n");
    printf("Vamos ver... 👀\n");
    printf("Está tudo certo.\n");
    printf("Aqui está o seu registro. 🪪\n");
    printf("--------------------------------\n\n");

    printf("Registro:\n");
    printf("--------------------------------\n");
    printf("Aventureiro %s 🙎🏻\n", nome);
    printf("classe: %s\n", classe);
    printf("Rank %c\n", rank);
    printf("Idade %d anos\n", idade);
    printf("Altura %.2f cm\n", altura);
    printf("Peso %.2f kg\n", peso);
    printf("\nAtributos:\n");
    printf("Vit: %d\tAgi: %d\n", vitalidade, agilidade);
    printf("For: %d\tInt: %d\n", forca, inteligencia);
    printf("Des: %d\tSor: %d\n", destreza, sorte);

    printf("Ataque Físico: %.2f \n", ataqueFisico);
    printf("Ataque Mágico: %.2f\n", ataqueMagico);
    printf("Pontos de Atributos: %d", pontosDeAtributos);
    printf("--------------------------------\n\n");

    printf("Recepcionista:\n");
    printf("--------------------------------\n");
    printf("Você pode entrar agora. 🚪✨\n");
    printf("--------------------------------\n\n");

    printf("Eldrin:\n");
    printf("--------------------------------\n");
    printf("Já era hora... então você finalmente apareceu. 😤\n");
    printf("Está pronto para o que nos espera? ⚔️\n");
    printf("Errr... qual é mesmo o seu nome? 🤔\n");
    printf("--------------------------------\n\n");

    printf("%s:\n", nome);
    printf("--------------------------------\n");
    printf("Meu nome é %s, senhor.\n", nome);
    printf("Sim, estou preparado. 💪🔥\n");
    printf("--------------------------------\n\n");

    printf("Eldrin:\n");
    printf("--------------------------------\n");
    printf("Ah... certo, agora me recordei. 😌\n");
    printf("Perfeito, %s.\n", nome);
    printf("Agora o grupo está completo. 🛡️⚔️\n");
    printf("--------------------------------\n\n");

    printf("Eldrin:\n");
    printf("--------------------------------\n");
    printf("Antes de irmos, %s,\n", nome);
    printf("Você deve distribuir seus pontos de atributos. 🎯\n");

    printf("Inteligencia: ");
    scanf("%d", &inteligencia);
    printf("Destreza: ");
    scanf("%d", &destreza);

    int resetPontosDeAtributos = pontosDeAtributos;

    pontosDeAtributos = pontosDeAtributos - (inteligencia + destreza);

    if (pontosDeAtributos < 0)
    {
        printf("Eldrin: Você tentou usar mais poder do que tem! Treine mais para obter mais poder!\n");
        pontosDeAtributos = resetPontosDeAtributos;
    }
    else if (pontosDeAtributos == 0)
    {
        printf("Eldrin: VVocê conhece bem seus limites!\n");
        ataqueMagico = (inteligencia * 3) + (destreza / 2.0) + (sorte);
        ataqueFisico = (forca * 2) + (destreza / 2.0) + (sorte);
        ataqueDistancia = (destreza * 3) + (inteligencia / 2.0) + (sorte);
    }
    else
    {
        printf("Eldrin: Voce ainda tem %d pontos de poder sobrando. Use-os bem!\n", pontosDeAtributos);
    }

    printf("Registro:\n");
    printf("--------------------------------\n");
    printf("Aventureiro %s 🙎🏻\n", nome);
    printf("classe: %s\n", classe);
    printf("Rank %c\n", rank);
    printf("Idade %d anos\n", idade);
    printf("Altura %.2f cm\n", altura);
    printf("Peso %.2f kg\n", peso);
    printf("\nAtributos:\n");
    printf("Vit: %d\tAgi: %d\n", vitalidade, agilidade);
    printf("For: %d\tInt: %d\n", forca, inteligencia);
    printf("Des: %d\tSor: %d\n", destreza, sorte);

    printf("Ataque Físico: %.2f \n", ataqueFisico);
    printf("Ataque Mágico: %.2f\n", ataqueMagico);
    printf("Pontos de Atributos: %d\n", pontosDeAtributos);
    printf("--------------------------------\n\n");

    

    return 0;
}