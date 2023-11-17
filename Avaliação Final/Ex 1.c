#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 3

/*1.(2,0) – Deseja-se um programa que registre os dados de 3 imóveis. Para cada imóvel, é necessário armazenar o nome, metragem de construção,
    metragem do terreno, valor e tipo (1-residencial, 2-comercial).  Com base as informações acima, favor implementar os
    procedimentos/funções abaixo:

    - Ler os dados do vetor de registro. Validar campos quando necessário; OK
    - Exibir os dados do vetor de registros. Exibir a quantidade de imóveis de cada tipo;OK
    - Retornar a média de valor dos imóveis lidos; OK
    - Exibir quais imóveis, que estão com o valor acima da média, com metragem de construção acima de 100m2, e são do tipo comercial; OK
*/

struct Imoveis
{
    char nome[50];
    float metragemC;
    float metragemT;
    float valor;
    int tipo;
};


void acimaMedia(struct Imoveis regImoveis[TF], float valorMedia){
    int i;

    for (i = 0; i < TF; i++)
    {
        if (regImoveis[i].valor > valorMedia && regImoveis[i].metragemC > 100 && regImoveis[i].tipo == 2)
        {
          printf("\nO imovel %s esta com o valor a cima da media, tem mais de 100m2 de construcao e eh comercial", regImoveis[i].nome);
        }  
    }
    
}

float calcMedia(struct Imoveis regImoveis[TF]){
    int i; float soma = 0, media = 0;

    for (i = 0; i < TF; i++)
    {
        soma +=regImoveis[i].valor;
    }
    media = soma / TF;
    return media;
}

void qtdeImoveis(struct Imoveis regImoveis[TF]){
    int i, contR = 0, contC = 0;

    for (i = 0; i < TF; i++)
    {
       if (regImoveis[i].tipo == 1)
       {
            contR++;
       }else{
            contC++;
       }
       
    }
    
    if (contR == 0)
    {
       printf("\nNao possui imovel residencial.");
    }else if (contR == 1)
    {
       printf("\nPossui um imovel residencial");
    }else
    {
        printf("\nPossuem %i imoveis residencias", contR);
    }

    if (contC == 0)
    {
       printf("\nNao possui imovel comerciais.");
    }else if (contC == 1)
    {
       printf("\nPossui um imovel comerciais");
    }else
    {
        printf("\nPossuem %i imoveis comerciais", contC);
    }
    
    
    
}

void exibindoImoveis(struct Imoveis regImoveis[TF]){
    int i;

    printf("\nExibindo dados dos imoveis!!");
    for (i = 0; i < TF; i++)
    {
       printf("\nNome: %s", regImoveis[i].nome);
       printf("\nMetragem Construcao: %0.1f", regImoveis[i].metragemC);
       printf("\nMetragem terreno: %0.1f", regImoveis[i].metragemT);
       printf("\nValor: %0.2f", regImoveis[i].valor);
       if (regImoveis[i].tipo == 1)
       {
            printf("\nImovel Residencial\n");
       }else{
            printf("\nImovel Comercial\n");
       }
       
    }
    
}

void carregandoImoveis(struct Imoveis regImoveis[TF]){
    int i;

    printf("\nRecebendo dados dos imoveis");
    for (i = 0; i < TF; i++)
    {
        fflush(stdin);
        printf("\nNome do imovel: ");
        gets(regImoveis[i].nome);
        printf("Metragem da contrucao: ");
        scanf("%f", &regImoveis[i].metragemC);
        printf("Metragem do terreno: ");
        scanf("%f", &regImoveis[i].metragemT);
        printf("Valor do imovel: ");
        scanf("%f", &regImoveis[i].valor);
        do
        {
            printf("Tipo do imovel 1-residencial 2-comercial: ");
            scanf("%i", &regImoveis[i].tipo);

            if (regImoveis[i].tipo != 1 && regImoveis[i].tipo != 2)
            {
                printf("\nOpvao invalida!!!\n");
            }
            
        } while (regImoveis[i].tipo != 1 && regImoveis[i].tipo != 2);
        
    }
    
}

int main(){
    struct Imoveis regImoveis[TF]; float mediaValor;

    carregandoImoveis(regImoveis);
    exibindoImoveis(regImoveis);
    qtdeImoveis(regImoveis);
    mediaValor = calcMedia(regImoveis);
    printf("\nMedia dos valores dos imoveis: %0.2f", mediaValor);
    acimaMedia(regImoveis, mediaValor);
}