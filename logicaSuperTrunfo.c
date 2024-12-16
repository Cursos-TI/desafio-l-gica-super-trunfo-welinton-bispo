#include <stdio.h>
#include <string.h>

// Defina uma estrutura para os atributos da carta
struct Carta {
    char Estado[31];
    char CodigoDaCarta[4]; 
    char NomeDaCidade[51]; 
    int Populacao;
    float AreaEmKmQuadrado;
    float PIB;
    int NumeroDePontosTuristicos;
};
// Função para coletar dados
void ColetandoDados(struct Carta *carta) {
    printf("Entre com o nome do estado:\n");
    scanf("%30s", carta->Estado);

    printf("Entre com o código da carta sendo ele a inicial do estado e um número de 1 a 4:\n");
    scanf("%3s", carta->CodigoDaCarta);

    printf("Entre com o nome da cidade:\n");
    scanf("%50s", carta->NomeDaCidade);

    printf("Entre com o número da população:\n");
    scanf("%d", &carta->Populacao);

    printf("Entre com o território em Km²:\n");
    scanf("%f", &carta->AreaEmKmQuadrado);

    printf("Entre com o PIB:\n");
    scanf("%f", &carta->PIB);

    printf("Entre com o número de pontos turísticos:\n");
    scanf("%d", &carta->NumeroDePontosTuristicos);
}

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(struct Carta carta) {
    return carta.Populacao / carta.AreaEmKmQuadrado;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(struct Carta carta) {
    return carta.PIB / carta.Populacao;
}

// Função para comparar duas cartas
void ComparaCartas(struct Carta carta1, struct Carta carta2) {
    int tipoComparacao;
    const char *CidadeVencedora;

    printf("Você deve escolher um número e o tipo de comparação.\n");
    printf("1. População\n");
    printf("2. PIB\n");
    printf("3. Densidade populacional\n");
    printf("4. PibPerCapita\n");

    printf("Escolha a comparação: ");
    scanf("%d", &tipoComparacao);

    switch (tipoComparacao) {
        case 1:
            if (carta1.Populacao > carta2.Populacao) {
                printf("%s tem maior população do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = carta1.NomeDaCidade;
            } else if (carta1.Populacao < carta2.Populacao) {
                printf("%s tem menor população do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = carta2.NomeDaCidade;
            } else {
                printf("%s tem a mesma população que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = "Empate";
            }
            break;

        case 2:
            if (carta1.PIB > carta2.PIB) {
                printf("%s tem maior PIB do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = carta1.NomeDaCidade;
            } else if (carta1.PIB < carta2.PIB) {
                printf("%s tem menor PIB do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = carta2.NomeDaCidade;
            } else {
                printf("%s tem o mesmo PIB que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                CidadeVencedora = "Empate";
            }
            break;

        case 3:
            {
                float densidade1 = calcularDensidadePopulacional(carta1);
                float densidade2 = calcularDensidadePopulacional(carta2);
                
                if (densidade1 > densidade2) {
                    printf("%s tem maior densidade populacional do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = carta2.NomeDaCidade;
                } else if (densidade1 < densidade2) {
                    printf("%s tem menor densidade populacional do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = carta1.NomeDaCidade;
                } else {
                    printf("%s tem a mesma densidade populacional que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = "Empate";
                }
            }
            break;

        case 4:
            {
                float PibPrCapita1 = calcularPibPerCapita(carta1);
                float PibPrCapita2 = calcularPibPerCapita(carta2);

                if (PibPrCapita1 > PibPrCapita2)
                {
                    printf("%s tem maior PibPerCapita do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = carta1.NomeDaCidade;
                } else if (PibPrCapita1 < PibPrCapita2)
                {
                    printf("%s tem menor PibPerCapita do que %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = carta2.NomeDaCidade;
                }else{
                    printf("%s tem o mesmo PibPerCapita %s\n", carta1.NomeDaCidade, carta2.NomeDaCidade);
                    CidadeVencedora = "Empate";
                }
            break;
                
            }

        default:
            printf("Opção inválida.\n");
            return;
    }
    if (strcmp(CidadeVencedora, "Empate") == 0)
    {
        printf("O resultado é um empate.\n");
    } else {
        printf("A cidade vencedora é: %s\n", CidadeVencedora);
    }
    
}

int main() {
    struct Carta carta1, carta2;
   
    // Coletando dados para a primeira carta
    printf("Carta 1:\n");
    ColetandoDados(&carta1);

    // Coletando dados para a segunda carta
    printf("\nCarta 2:\n");
    ColetandoDados(&carta2);

    // Comparando as cartas
    printf("\nComparando cartas:\n");
    ComparaCartas(carta1, carta2);

    return 0;

}