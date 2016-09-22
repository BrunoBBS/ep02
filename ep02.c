#include "matriz.h"
#include "types.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int **tab;
int podeMover(pos buraco, int ultdDir)
{
    
}

pos procuraBuraco(int **tab, pos ultBur, int l, int c)
{
    int i, j;
    pos ret;
    for (i = ultBur.l; i < l;i++)
        for (j = ultBur.c + 1; j < c; j++)
            if (tab[i][j] == -1)
            {
                ret.l = i;
                ret.c = j;
                return ret; 
            }
    ret.l = -1;
    ret.c = -1;
    return ret;
}

int main()
{
    int c, l, i, j, dir;
    pos aux;
    pilha *p;

    scanf("%d %d", &c, &l);
    tab = criaMatriz(l, c);
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &tab[i][j]);
    aux.l = 0;
    aux.c = -1;
    aux = procuraBuraco(tab, aux, l, c);
    if (aux.l == -1 && aux.c == -1)
    {
        printf("Impossivel\n");
    }
    p = criaPilha((l * c)/2);
    dir = podeMover(aux,0);
}


