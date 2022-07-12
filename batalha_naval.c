#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, l, c, ponto = 0, ntentativa = 0;

    int matriz[4][4] = {
        {0, 0, 1, 1}, 
        {0, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 0, 0, 0}
    };

    int matrizcontrolo[4][4] = {
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}
    };
        
    char array1[4][5] = {
        "0000", 
        "0000", 
        "0000", 
        "0000"
    };

    for (i = 0; i < 4; i++)
    {
        do
        { 
            printf("Tentativa %d\n", ntentativa + 1);
            do
            {
                printf("Linha:\n");
                scanf("%d", &l);
            } while (l < 1 || l > 4);
            do
            {
                printf("Coluna:\n");
                scanf("%d", &c);
            } while (c < 1 || c > 4);
        } while (matrizcontrolo[l-1][c-1] == 1);

        matrizcontrolo[l-1][c-1] = 1;
        if (matriz[l - 1][c - 1] == 0)
        {
            printf("Splash!\n\n");
            array1[l-1][c-1] = 'x';
        }
        else
        {
            printf("Boom!\n\n");
            ponto = ponto + 2;
            i--;
            array1[l - 1][c - 1]= 'S';
        }
        
        ntentativa++;
    }
    
    printf("\nO campo de batalha foi\n");
    for (i = 0; i < 4; i++)
    {   printf("\n");
        for (j = 0; j < 4; j++){
        printf("%c ", array1[i][j]);
    }
    }

    if (ponto == 8)
    {
        printf("\n\nParabéns, acertou em todos os barcos e a sua pontuação foi de %d pontos",
               ponto);
    }
    else{
        printf("\n\nA sua pontuação foi de %d pontos", ponto);
    }
    return 0;
}

