#include "types.h"
#ifndef PILHA_H
#define PILHA_H

/*A função recebe um pontiro para uma pilha e retorna 0 se ela estiver vazia.*/
int pilhaVazia(pilha *p);

/*A função recebe o tamanho maximo para pilha e retorna a pilha deste tmanho.*/
pilha *criaPilha(int max);

/*A função recebe um ponteiro para uma pilha e realoca para uma matriz 1.2 vez
 * maior.*/
void realocaPilha(pilha *p);

/*A função recebe um ponteiro para uma pilha e um movimento e os coloca na
 * pilha.*/
void empilha(pilha *p, movimento x);

/*A função recebe um ponteiro para uma pilha e retrna o elemento to topo.*/
movimento desempilha(pilha *p);

/*A função recebe um ponteiro para uma pilha e a destrói.*/
void destroiPilha(pilha *p);

#endif
