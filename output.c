#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "output.h"



void out_Map(S_MAP* Map)
{
    int i,j;

    system("clear");

    for(i=0;i<Map->size_row;i++)
    {
        for(j=0;j<Map->size_col;j++)
        {
            printf( "%c ", (Map->arr_map)[i][j]);
        }
        printf("\n");
    }

}