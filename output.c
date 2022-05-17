#include "output.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>


void out_Map(S_MAP* Map)
{
    int i,j;

    system("clear");

    for(i=0;i<Map->size_col;i++)
    {
        for(j=0;j<Map->size_row;j++)
        {
            printf( "%c ", (Map->arr_map)[i][j]);
        }
        printf("\n");
    }

}