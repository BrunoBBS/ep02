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
    printf("Procurando direcao do %d %d a aprtir da %d \n", buraco.l, buraco.c, ultdDir);
    switch (ultdDir)
    {
        case 0: if (buraco.l > 2 && (tab[buraco.l - 2][buraco.c]) == 1 
                    && tab[buraco.l - 1][buraco.c] == 1)
                    return 0;
        case 1: if (buraco.c < (n-2) && (tab[buraco.l][buraco.c + 2]) == 1 
                    && tab[buraco.l][buraco.c + 1] == 1)
                    return 1;
        case 2: if (buraco.l < (m-2) && (tab[buraco.l + 2][buraco.c]) == 1 
                    && tab[buraco.l + 1][buraco.c] == 1)
                    return 2;
        case 3: if (buraco.c > 2 && (tab[buraco.l][buraco.c - 2]) == 1 
                    && tab[buraco.l][buraco.c - 2] == 1)
                    return 3;
        default: return 4;
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

 /*A funcao recebe o tabulero como uma matriz, a posicao do antigo buraco e a
  * direcao da qual foi feita  a jogada e desfaz o movimento.*/
void desmove(int **tab, pos buraco, int dir)
{
    switch(dir)
    {
        case 0: tab[buraco.l][buraco.c] = -1; 
                tab[buraco.l - 2][buraco.c] = 1;
                tab[buraco.l - 1][buraco.c] = 1;
                break;
        case 1: tab[buraco.l][buraco.c] = -1; 
                tab[buraco.l][buraco.c + 2] = 1;
                tab[buraco.l][buraco.c + 1] = 1;
                break;
        case 2: tab[buraco.l][buraco.c] = -1; 
                tab[buraco.l + 2][buraco.c] = 1;
                tab[buraco.l + 1][buraco.c] = 1;
                break;
        case 3: tab[buraco.l][buraco.c] = -1; 
                tab[buraco.l][buraco.c - 2] = 1;
                tab[buraco.l][buraco.c - 1] = 1;
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
    int i, j, k = (ultBur.c + 1);
    pos ret;
    printf("entrou no %d %d pra procurar buraco\n", ultBur.l, (ultBur.c + 1));
    for (i = ultBur.l; i < l; i++)
    {
        for (j = k; j < c; j++)
        {
            printf("i = %d j = %d valor = %d \n", i, j, tab[i][j]);
            if (tab[i][j] == -1)
            {
                printf("achou o buraco %d %d \n", i, j);
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
        printf("%d:%d-%d:%d", lp, cp, p -> l[i], p -> c[i]);
    }
}

int main()
{
    /*Falta implementar o backtrack e fazer ele voltar e tentar uma direcaoo
     * nova antes de um passos novo.*/
    int c, l, i, j, acabou = 0;
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
        printf("Imprimindo tabuleiro...\n");
        for (i = 0; i < l; i++)
        {
            for (j = 0; j < c; j++)
                printf("%d\t",tab[i][j]);
            printf("\n");
        }
        
        printf("Checando se acabou...\n");
        acabou = 1;
        for (i = 0; i < l && acabou == 1; i++)
            for (j = 0; j < c && acabou == 1; j++)
                if (tab[i][j] != final[i][j])
                    acabou = 0;
        
        if (acabou == 1)
            break;

        printf("Procurando buraco...\n");
        mov.pos = procuraBuraco(tab, mov.pos, l, c);
        mov.dir = -1;
        if (mov.pos.l == -1)
        {
            printf("Voltando no tempo...\n");
            /*~~BACKTRACK~~*/
            if (pilhaVazia(*p) > 0)
            {
            printf("topo : %d", p -> topo);
            mov = desempilha(p);
            printf("desempilhou %d %d %d", mov.pos.l, mov.pos.c, mov.dir);
            desmove(tab, mov.pos, mov.dir);
            }
            else
            {
                printf("merda");       
            }
        }
                
        printf("Procurando direcao...\n");
        mov.dir = podeMover(tab, mov.pos, mov.dir, l, c);

        if (mov.dir < 4)
        {
            printf("Movendo...\n");
            move(tab, mov.pos, mov.dir);
            printf("Empilhando %d %d %d \n", mov.pos.l, mov.pos.c, mov.dir);
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
