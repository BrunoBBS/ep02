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
    p -> v = malloc(max * sizeof(movimento));
    p -> topo = 0;
    p -> max = max;
    return p;
}

void realocaPilha(pilha *p)
{
    int maxNovo = p -> max * 1.2;
    movimento *w;
    int i;
    w = malloc(maxNovo * sizeof(movimento));
    for (i = 0; i < p -> max; i++)
        w[i] = p -> v[i];
    free(p -> v);
    p -> v = w;
}

void empilha(pilha *p, movimento x)
{
    if (p -> topo == p -> max )
        realocaPilha(p);
    p -> v[p -> topo] = x;
    p -> topo ++;
}


int **criaMatriz(int l, int c)
{
    int **m;
    int i;
    m = malloc(l * sizeof(int *));
    for (i = 0; i < l; i++)
        m[i] = malloc(c * sizeof(int));
    return m;
}

movimento desempilha(pilha *p)
{
    movimento mov =  p -> v[p -> topo];
    p -> topo -= 1;
    return mov; 
}

void destroiPilha(pilha *p)
{
    free(p -> v);
    free(p);
}
