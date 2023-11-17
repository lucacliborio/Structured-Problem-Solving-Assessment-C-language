#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tl 2
#define tc 2

/*3.(1,0) - Leia duas matrizes 2 x 2 e escreva uma terceira matriz com a média dos valores de cada posição das matrizes lidas.
    Exibir a matriz resultante.
*/
void criandoDados3(int dados1[tl][tc], int dados2[tl][tc], float dados3[tl][tc]){
    int l, c; float soma, media = 0;

   for (l = 0; l < tl; l++)
   {
        for (c = 0; c < tc; c++)
        {
            soma = dados1[l][c] + dados2[l][c];
            media = soma / 2;
            dados3[l][c] = media;
        }
   }
   

    printf("\nExibindo nova matriz\n");
    for (l = 0; l < tl; l++)
   {
        for (c = 0; c < tc; c++)
        {
            printf(" %0.1f |", dados3[l][c]);
        }
        printf("\n");
   }
     
    

}

void carregandoDados2(int dados[tl][tc]){
    int l, c;

    printf("\nRecebendo dados da matriz 2\n");
    for (l = 0; l < tl; l++)
    {
       for (c = 0; c < tc; c++)
       {
        printf("Informe o valor da linha %i e coluna %i: ", l, c);
        scanf("%i", &dados[l][c]);
       }
       
    }
}

void carregandoDados1(int dados[tl][tc]){
    int l, c;

    printf("\nRecebendo dados da matriz 1\n");
    for (l = 0; l < tl; l++)
    {
       for (c = 0; c < tc; c++)
       {
        printf("Informe o valor da linha %i e coluna %i: ", l, c);
        scanf("%i", &dados[l][c]);
       }
       
    }
    
}

int main(){
    int dados1[tl][tc], dados2[tl][tc]; float dados3[tl][tc];

    carregandoDados1(dados1);
    carregandoDados2(dados2);
    criandoDados3(dados1, dados2, dados3);
}
