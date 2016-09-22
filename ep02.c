#include "matriz.h"
#include "types.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int **tab; 
int podeMover(movimento *mov)
{
    if ();
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
            }
}

int main()
{
    int c, l, i, j;
    pos aux;
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

    }
}


