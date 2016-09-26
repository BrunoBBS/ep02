#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

int **criaMatriz(int l, int c)
{
    int **mat;
    int i;
    mat = malloc(l * sizeof(int*));
    if (mat != NULL)
        for (i = 0; i < l; i++)
        {
            mat[i] = malloc(c * sizeof(int));
            if (mat[i] == NULL)
                return NULL;
        }
    return mat;
}

void destroiMatriz(int **mat, int l)
{
    int i;
    for (i = 0; i < l; i++)
        free(mat[i]);
    free(mat);
}

