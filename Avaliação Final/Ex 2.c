#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 3

/*2. (2,0) - Foi realizada uma pesquisa de algumas características de 3 barcos. De cada barco foram coletados os seguintes dados:
    porte (1-grande, 2-médio, 3-pequenho), Casco (1 – Fibra, 2 – Alumínio), potência do motor, horas de uso do motor. Com base as
    informações acima, favor implementar os procedimentos/funções abaixo:

    - Ler os dados em um vetor de registro. Validar as leituras quando necessário; OK
    - Retornar o barco com maior potência no motor; OK
    - Exibir os barcos de grande porte, com casco de fibra; OK
    - Calcular a média horas de uso do motor dos barcos de grande porte; OK
*/
struct Barcos
{
    int porte;
    int casco;
    float potencia;
    float horas;
};
void horasGrande(struct Barcos regBarcos[TF]){
    int i, cont = 0; float soma = 0, media = 0;

    for (i = 0; i < TF; i++)
    {
        if (regBarcos[i].porte == 1)
        {
            soma += regBarcos[i].horas;
            cont++;
        }
        
    }
    media = soma / cont;
    printf("\nMedia de horas de uso do motor dos barcos de grande porte: %0.2f", media);
}

void grandePorte(struct Barcos regBarcos[TF]){
    int i;

    printf("\nExibindo barco grande com casco em fibra");
    for (i = 0; i < TF; i++)
    {
        
        if (regBarcos[i].porte == 1 && regBarcos[i].casco == 1)
        {
            printf("\nPorte: %i", regBarcos[i].porte);
            printf("\nCasco: %i", regBarcos[i].casco);
            printf("\nPotencia %0.1f", regBarcos[i].potencia);
            printf("\nHoras do motor: %0.1f", regBarcos[i].horas);
        }
        
    }
    
}

float maiorPotencia(struct Barcos regBarcos[TF]){
    int i; float maiorP;

    for (i = 0; i < TF; i++)
    {
        if (i == 0)
        {
            maiorP = regBarcos[i].potencia;
        }else if (regBarcos[i].potencia > maiorP)
        {
            maiorP = regBarcos[i].potencia;
        }
        
    }
    return maiorP;
}

void carregandoBarcos(struct Barcos regBarcos[TF]){
    int i;

    printf("\nRecebendo dados dos barcos!");
    for (i = 0; i < TF; i++)
    {
        do
        {
            printf("\nPorte do barco 1-grande, 2-médio, 3-pequeno: ");
            scanf("%i", &regBarcos[i].porte);

            if (regBarcos[i].porte != 1 && regBarcos[i].porte != 2 && regBarcos[i].porte != 3)
            {
               printf("\nOpcao invalida!\n");
            }
            
        } while (regBarcos[i].porte != 1 && regBarcos[i].porte != 2 && regBarcos[i].porte != 3);

        do
        {
            printf("Casco do barco 1 – Fibra, 2 – Alumínio:  ");
            scanf("%i", &regBarcos[i].casco);

            if (regBarcos[i].casco != 1 && regBarcos[i].casco != 2)
            {
                printf("\nOpcao invalida!\n");
            }
            
        } while (regBarcos[i].casco != 1 && regBarcos[i].casco != 2);

        printf("Potencia do barco: ");
        scanf("%f", &regBarcos[i].potencia);
        printf("Horas de uso do motor: ");
        scanf("%f", &regBarcos[i].horas);
        
    }

}

int main(){
    struct Barcos regBarcos[TF]; float potenciaMaior;

    carregandoBarcos(regBarcos);
    potenciaMaior = maiorPotencia(regBarcos);
    printf("\nO barco que tem a maior potencia tem %0.1f cavalos de potencia.", potenciaMaior);
    grandePorte(regBarcos);
    horasGrande(regBarcos);
}