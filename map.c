#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "constants.h"
#include "mem.h"
#include "snake.h"
#include "map.h"
#include "random.h"
#include "output.h"

/*
Handles the map 
 - Its struct and associated char** map array


Unhandled errors
    - Out of memory (mallocs)
*/

/*
Initialises a map struct
    - If map size is invalid returns NULL
*/

S_MAP* initMap(int r, int c)
{
    S_MAP* s_map;
    s_map = NULL;

    if(isValidMap(r,c))
    {
        s_map = initEmptyMapStruct();
        

        /*
        CRITICAL POINT
        (r+2) and (c+2) to accomodate '*' border
        */
        s_map->size_row = (r+2);
        s_map->size_col = (c+2);
        s_map->arr_map = initEmptyMapArray(s_map->size_row,s_map->size_col);

        /*now spawn border and food*/
        spawnBorder(s_map);
        
    }

    return s_map;
}

S_MAP* initEmptyMapStruct()
{
    return (S_MAP*)malloc(sizeof(S_MAP));
}


/*
Takes in total map size
Will return a pointer to a 2d array of size m_rows x m_cols
*/
char** initEmptyMapArray(int m_rows, int m_cols)
{
    char** a_map;
    char* cols;
    int i;


    /*Create Map Rows*/
    a_map = (char**)malloc(m_rows*sizeof(char*));

    /*Link map rows*/
    for(i=0;i<m_rows;i++)
    {
        cols = (char*)malloc(m_cols*sizeof(char));

        a_map[i] = cols;
    }

    return a_map;
}



/*Removes snek from map arrays*/
void clearSnake(char** arr_map,NODE* snake_head)
{
    NODE* n;
    S_SNODE* snakeNode;
    n = snake_head;
    while(n != NULL)
    {
        snakeNode = (S_SNODE*)(n->data);
        arr_map[snakeNode->row][snakeNode->col] = EMPTY_SYM;
        
        n=n->next;
    }
    
}



/*Goes through linked list and spawns the snake, assumed valid snake positioning*/
void spawnSnake(int i,S_MAP* Map,NODE* n)
{
    S_SNODE* snode;
    snode = (S_SNODE*)(n->data);

    /*Logic for whether the node is a head,body or tail*/
    if(i==I_HEAD)
    {
        spawnSnake(++i,Map,n->next);
        updateMap(Map,snode->row,snode->col,SNAKE_H[snode->dir]);
    }
    else if(n->next!=NULL)
    {
        spawnSnake(++i,Map,n->next);
        updateMap(Map,snode->row,snode->col,SNAKE_B[snode->dir]);
    }
    else
    {
        updateMap(Map,snode->row,snode->col,SNAKE_T[snode->dir]);
    }

}

void updateMap(S_MAP* Map, int r, int c, char ch)
{
    (Map->arr_map)[r][c] = ch;
}


/* Puts a BORDER_SYM character at the first and last row and first and last column
 The map is already the required map size */
void spawnBorder(S_MAP* s_map)
{
    int j,k;
    char** map;
    int m_rows,m_cols;

    m_rows = s_map->size_row;
    m_cols = s_map->size_col;
    map = s_map->arr_map;

    /*Place in border*/
    for(j=0;j<m_rows;j++)
    {
        for(k=0;k<m_cols;k++)
        {
            if(j==0||j==(m_rows-1)) /*First last row*/
            {
                map[j][k] = BORDER_SYM;
            }
            else if(k==0||k==(m_cols-1))/*Or First or last col*/
            {
                map[j][k] = BORDER_SYM;
            }
            else
            {
                map[j][k] = EMPTY_SYM;
            }
        }

    }
}


/*Generates random row, column (within playable map coords)
    checks that the position is empty then places food onto map array*/
void spawnFood(S_MAP* Map)
{
    int r,c;
    do
    {
        r = random(1,(Map->size_row)-2); /*-2 for index and border*/
        c = random(1,(Map->size_col)-2);
    }while(!isObj(Map->arr_map,r,c,EMPTY_SYM));
    

    (Map->arr_map)[r][c] = FOOD_SYM;
}

/*
Checks to see if a location contains a certain char.
obj could be any char, but should use hardcoded vals...
FOOD_SYM,EMPTY_SYM,BORDER.

Bounds should be checked before using
*/
int isObj(char** arr_map,int r,int c,char obj)
{
    int result;
    result = FALSE;
    if(arr_map[r][c] == obj)
    {
        result = TRUE;
    }

    return result;
}

int isValidMap(int m_row,int m_col)
{
    int isValid = FALSE;

    if(m_row>MIN_ROW_MAP)
    {
        if(m_col>MIN_COL_MAP)
        {
            isValid = TRUE;
        }
        else
        {
            printf("Invalid parameter <col_map>. Should be over 5.\n");
        }
    }
    else
    {
        printf("Invalid parameter <row_map>. Should be over 5.\n");
    }
    
    return isValid;
}

void destroyMap(S_MAP* map)
{
    int i;
    /*iterate rows with pointers to columns and free them*/
    for(i=0;i<map->size_row;i++)
    {
        free((map->arr_map)[i]);
    }

    /*Then free the row array itself*/
    free(map->arr_map);

    /*Then destroy the struct*/
    free(map);
}


void printSNode(NODE* n)
{
    S_SNODE* sn = (S_SNODE*)(n->data);
    printf("SNODE: r - %d, c - %d, d - %d\n",sn->row,sn->col,sn->dir);
}

