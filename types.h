#ifndef TYPES_H
#define TYPES_H


struct pos_s{
    int c;
    int l;
};

struct movimento_s {
    int pos;
    int dir;
};

struct pilha_s {
    movimento *v;
    int topo;
    int max;
};

typedef struct pos_s pos;
typedef struct movimento_s movimento;
typedef struct pilha_s pilha;

#endif
