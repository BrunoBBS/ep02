#ifndef MATRIZ_H
#define MATRIZ_H

/*A função recebe o numero de linhas r retorna uma matriz de mesmas 
*dimensões.*/
int **criaMatriz(int l, int c);

/*A função recebe uma matriz, e seu número de linhas e a destrói.*/
void destroiMatriz(int **mat,int l);

#endif
