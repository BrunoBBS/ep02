#include "matriz.h"
#include "types.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*A funcao recebe a matriz tabuleiro preenchida de 0s e 1s, a posicao de uma
 * peca, a direcao do ultimo movimento (-1 caso seja o primeiro para aquela
 * peca) e o numeo de linhas e colunas da matriz e retorna o numero da posicao
 * da qual pode mover a partir da ultima direcao (retorna 4 caso nao haja 
 * movimenos possiveis).*/
int podeMover(int **tab, pos peca, int ultdDir, int m, int n)
{
    ultdDir += 1;
    switch (ultdDir)
    {
        case 0: if (peca.l > 2 && (tab[peca.l - 2][peca.c]) == -1 
                    && tab[peca.l - 1][peca.c] == 1)
                    return 0;
        case 1: if (peca.c < (n-2) && (tab[peca.l][peca.c + 2]) == -1 
                    && tab[peca.l][peca.c + 1] == 1)
                    return 1;
        case 2: if (peca.l < (m-2) && (tab[peca.l + 2][peca.c]) == -1 
                    && tab[peca.l + 1][peca.c] == 1)
                    return 2;
        case 3: if (peca.c > 2 && (tab[peca.l][peca.c - 2]) == -1 
                    && tab[peca.l][peca.c - 2] == 1)
                    return 3;
        default: return 4;
    }
}

/* A funcao recebe uma matriz com o tabuleiro preenchido de 0s e 1s, a posicao
 * da peca no qual sera feito o movimeto e a direcao da qual sera retirada a
 * peca do movimento e executa na matriz as substituicoes do movimeno.*/
void move(int **tab, pos peca, int dir)
{ 
    switch(dir)
    {
        case 0: tab[peca.l][peca.c] = -1; 
                tab[peca.l - 2][peca.c] = 1;
                tab[peca.l - 1][peca.c] = -1;
                break;
        case 1: tab[peca.l][peca.c] = -1; 
                tab[peca.l][peca.c + 2] = 1;
                tab[peca.l][peca.c + 1] = -1;
                break;
        case 2: tab[peca.l][peca.c] = -1; 
                tab[peca.l + 2][peca.c] = 1;
                tab[peca.l + 1][peca.c] = -1;
                break;
        case 3: tab[peca.l][peca.c] = -1; 
                tab[peca.l][peca.c - 2] = 1;
                tab[peca.l][peca.c - 1] = -1;
                break;
    }
}

 /*A funcao recebe o tabulero como uma matriz, a posicao do antiga peca e a
  * direcao da qual foi feita  a jogada e desfaz o movimento.*/
void desmove(int **tab, pos peca, int dir)
{
    switch(dir)
    {
        case 0: tab[peca.l][peca.c] = 1; 
                tab[peca.l - 2][peca.c] = -1;
                tab[peca.l - 1][peca.c] = 1;
                break;
        case 1: tab[peca.l][peca.c] = 1; 
                tab[peca.l][peca.c + 2] = -1;
                tab[peca.l][peca.c + 1] = 1;
                break;
        case 2: tab[peca.l][peca.c] = 1; 
                tab[peca.l + 2][peca.c] = -1;
                tab[peca.l + 1][peca.c] = 1;
                break;
        case 3: tab[peca.l][peca.c] = 1; 
                tab[peca.l][peca.c - 2] = -1;
                tab[peca.l][peca.c - 1] = 1;
                break;
    }
}

/*A funcao recebe uma matriz com o tabuleiro preenchido de 0s e 1s, a posicao
 * do ultimo peca encontrado (em caso de backtracking e (0,-1) caso seja a 
 * primeira procura), o numero de linhas e colunas da matriz tabuleiro e 
 * retorna uma posicao caso enconte um peca (-1) e retorna a posicao (-1,-1)
 * caso nao encontre um peca.*/
pos procuraPeca(int **tab, pos ultPec, int l, int c)
{
    int i, j, k = (ultPec.c + 1);
    pos ret;
    printf("entrou no %d %d pra procurar peca\n", ultPec.l, (ultPec.c + 1));
    for (i = ultPec.l; i < l; i++)
    {
        for (j = k; j < c; j++)
        {
            if (tab[i][j] == 1)
            {
                ret.l = i;
                ret.c = j;
                return ret; 
            }
        }
        k = 0;
    }
    ret.l = -1;
    ret.c = -1;
    return ret;
}

/*A funcao recebe a pilha com os passos armazenados e os imprime na ordem
 * correta e no formato correto. */
void imprimePassos(pilha *p)
{
    int i, lp, cp;
    for (i = 0; i < p -> topo ; i++)
    {
        switch (p -> d[i])
        {
            case 0: lp = (p -> l[i]) - 2; cp = p -> c[i]; break;
            case 1: lp = p -> l[i]; cp = (p -> c[i]) + 2; break;
            case 2: lp = (p -> l[i]) + 2; cp = p -> c[i]; break;
            case 3: lp = p -> l[i]; cp = (p -> c[i]) - 2; break;
        }
        printf("%d:%d-%d:%d", p -> l[i], p -> c[i], lp, cp);
    }
}

int main()
{
    /*Falta implementar o backtrack e fazer ele voltar e tentar uma direcaoo
     * nova antes de um passos novo.*/
    int c, l, i, j, acabou = 0, back = 0;
    int **tab, **final;
    pilha *p;
    movimento mov;
    scanf("%d %d", &c, &l);
    p = criaPilha((l * c));
    tab = criaMatriz(l, c);
    final = criaMatriz(l, c);

    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
        {
            scanf("%d", &tab[i][j]);
            final[i][j] = -(tab[i][j]);
        }

    mov.dir = -1;
    mov.pos.l = 0;
    mov.pos.c = -1;

    do
    { 
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
                printf("%d\t",tab[i][j]);
            printf("\n");
        }
        
        acabou = 1;
        for (i = 0; i < l && acabou == 1; i++)
            for (j = 0; j < c && acabou == 1; j++)
                if (tab[i][j] != final[i][j])
                    acabou = 0;
        
        if (acabou == 1)
            break;

        mov.pos = procuraPeca(tab, mov.pos, l, c);
        mov.dir = -1;
        if (mov.pos.l == -1)
        {
            /*~~BACKTRACK~~*/
            if (pilhaVazia(p) > 0)
            {
                printf("desempilhou\n");
                mov = desempilha(p); 
                desmove(tab, mov.pos, mov.dir);
                back = 1;
            }
        }
                
        if (mov.pos.l > -1)
            mov.dir = podeMover(tab, mov.pos, mov.dir, l, c);

        if (back == 1)
        {
            mov.pos.l = 0;
            mov.pos.c = -1;
            back = 0;
        }

        if (mov.dir < 4)
        {
            printf("Movendo...\n");
            move(tab, mov.pos, mov.dir);
            empilha(p,mov);
            mov.pos.c = -1;
            mov.pos.l = 0;
        }

    } while(!(mov.pos.l == -1 && mov.pos.c == -1) && acabou == 0);
    
    if (acabou == 0)
        printf("Impossivel\n");
    else if (acabou == 1)
        imprimePassos(p);

    return 0;
}
