#include "pilha.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>


int pilhaVazia(pilha  p)
{
    return p.topo;
}

pilha *criaPilha(int max)
{
    pilha *p;
    p = malloc(sizeof(pilha));
    p -> l = malloc(max * sizeof(int));
    p -> c = malloc(max * sizeof(int));
    p -> d = malloc(max * sizeof(int));
    p -> topo = 0;
    p -> max = max;
    return p;
}

void realocaPilha(pilha *p)
{
    int maxNovo = p -> max * 1.2;
    int *w;
    int i;
    w = malloc(maxNovo * sizeof(int));
    for (i = 0; i < p -> max; i++)
        w[i] = p -> l[i];
    free(p -> l);
    p -> l = w;

    for (i = 0; i < p -> max; i++)
        w[i] = p -> c[i];
    free(p -> c);
    p -> c = w;

    for (i = 0; i < p -> max; i++)
        w[i] = p -> d[i];
    free(p -> d);
    p -> d = w;
}

void empilha(pilha *p, movimento x)
{
    if (p -> topo == p -> max )
        realocaPilha(p);
    p -> l[p -> topo] = x.pos.l;
    p -> c[p -> topo] = x.pos.c;
    p -> d[p -> topo] = x.dir;
    p -> topo ++;
}

movimento desempilha(pilha *p)
{
    movimento mov;
    mov.pos.l =  p -> l[p -> topo];
    mov.pos.c =  p -> c[p -> topo];
    mov.dir =  p -> d[p -> topo];
    p -> topo -= 1;
    return mov; 
}

void destroiPilha(pilha *p)
{
    free(p -> l);
    free(p -> c);
    free(p -> d);
    free(p);
}
