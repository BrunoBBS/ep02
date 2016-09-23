#include "matriz.h"
#include "types.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*A funcao recebe a matriz tabuleiro preenchida de 0s e 1s, a posicao de um
 * buraco, a direcao do ultimo movimento (-1 caso seja o primeiro para aquele
 * buraco) e o numeo de linhas e colunas da matriz e retorna o numero da posicao
 * da qual pode mover a partir da ultima direcao (retorna 4 caso nao haja 
 * movimenos possiveis).*/
int podeMover(int **tab, pos buraco, int ultdDir, int m, int n)
{
    ultdDir += 1;
    switch (ultdDir)
    {
        case 0: if (buraco.l > 2 && (tab[buraco.l - 2][buraco.c]) == 1)
                    return 0;
        case 1: if (buraco.c < (n-2) && (tab[buraco.l][buraco.c + 2]) == 1)
                    return 1;
        case 2: if (buraco.l < (m-2) && (tab[buraco.l + 2][buraco.c]) == 1)
                    return 2;
        case 3: if (buraco.c > 2 && (tab[buraco.l][buraco.c - 2]) == 1)
                    return 3;
        default: return -1;
    }
}

/* A funcao recebe uma matriz com o tabuleiro preenchido de 0s e 1s, a posicao
 * do buraco no qual sera feito o movimeto e a direcao da qual sera retirada a
 * peca do movimento e executa na matriz as substituicoes do movimeno.*/
void move(int **tab, pos buraco, int dir)
{ 
    switch(dir)
    {
        case 0: tab[buraco.l][buraco.c] = 1; 
                tab[buraco.l - 2][buraco.c] = -1;
                tab[buraco.l - 1][buraco.c] = -1;
                break;
        case 1: tab[buraco.l][buraco.c] = 1; 
                tab[buraco.l][buraco.c + 2] = -1;
                tab[buraco.l][buraco.c + 1] = -1;
                break;
        case 2: tab[buraco.l][buraco.c] = 1; 
                tab[buraco.l + 2][buraco.c] = -1;
                tab[buraco.l + 1][buraco.c] = -1;
                break;
        case 3: tab[buraco.l][buraco.c] = 1; 
                tab[buraco.l][buraco.c - 2] = -1;
                tab[buraco.l][buraco.c - 1] = -1;
                break;
    }
}

/*A funcao recebe uma matriz com o tabuleiro preenchido de 0s e 1s, a posicao
 * do ultimo buraco encontrado (em caso de backtracking e (0,-1) caso seja a 
 * primeira procura), o numero de linhas e colunas da matriz tabuleiro e 
 * retorna uma posicao caso enconte um buraco (-1) e retorna a posicao (-1,-1)
 * caso nao encontre um buraco.*/
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
    int c, l, i, j, aux, acabou;
    int **tab, **final;
    pilha *p;
    movimento mov;
    mov.pos.l = 0;
    mov.pos.c = -1;
    p = criaPilha((l * c)/2);
    mov.dir = -1;

    aux = scanf("%d %d", &c, &l);
    tab = criaMatriz(l, c);
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
        {
            scanf("%d", &tab[i][j]);
            final[i][j] = -(tab[i][j]);
        }
    while(!acabou)
    {
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
                printf("%d\t",tab[i][j]);
            printf("\n");
        }
        mov.pos = procuraBuraco(tab, mov.pos, l, c);
        if (mov.pos.l == -1 && mov.pos.c == -1) 
        {
            /*Nao achou um buraco*/
            printf("Impossivel\n");
            return 0;
        }
        mov.dir = podeMover(tab, mov.pos, mov.dir, l, c);
        if (mov.dir <= 3 && mov.dir >= 0)
        {
            empilha(p, mov);
            move(tab, mov.pos, mov.dir);
        }
        else
        {
            /*~~BACKTRACK~~*/
            if (pilhaVazia(*p))
            {
                /*Nao tem decisao para voltar atras*/
                printf("Impossivel\n");
                return 0;
            }
            mov = desempilha(p);
        }
        acabou = 1;
        /*Verifica se ja chegou no fim*/
        for (i = 0; i < l; i++)
            for (j = 0; j < c; j++)
                if (tab[i][j] != final[i][j])
                    acabou = 0;
    }
}


