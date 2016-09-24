#ifndef TYPES_H
#define TYPES_H

typedef struct pos_s pos;
typedef struct movimento_s movimento;
typedef struct pilha_s pilha;

struct pos_s{
    int c;
    int l;
};

struct movimento_s {
    pos pos;
    int dir;
};

struct pilha_s {
    int *l;
    int *c;
    int *d;
    int topo;
    int max;
};


#endif
