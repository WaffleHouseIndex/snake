
#include <stdlib.h>
#include "snake.h"



static const char* P_SNAKE[P_SNAKE_LEN] = {SNAKE_H,SNAKE_B,SNAKE_T};

/*Contains snake game specific functions*/

/*
Takes in row,col and ch
Returns a a snake node ptr.
If an error occurs will return a NULL ptr
*/
SnakeNode* initSnakeNodeWithCh(int row,int col, char ch)
{
    E_DIRE dir;
    SnakeNode* newSnakeNode;

    dir = getChToDirEnum(ch);

    /*Check if a valid dir*/
    if(dir != E_NULL)
    {
        newSnakeNode = initSnakeNodeWithDir(row,col,dir);
    }
    else
    {
        newSnakeNode = NULL;
    }

    return newSnakeNode;
}

SnakeNode* initSnakeNodeWithDir(int row,int col, E_DIRE dir)
{
    SnakeNode* newSnakeNode;
    newSnakeNode = initEmptySnakeNode();
    newSnakeNode->row = row;
    newSnakeNode->col = col;
    newSnakeNode->dir = dir;
    return newSnakeNode;
}

SnakeNode* initEmptySnakeNode()
{
    return (SnakeNode*)malloc(sizeof(SnakeNode));
}


/*Takes in a char if it matches a valid char returns the direction
    if '#' is given will return RIGHT
    if given an invalid character will return NULL
*/
E_DIRE getChToDirEnum(char ch)
{
    int i,j;

    E_DIRE dir = E_NULL;
    for(i=0;i<(P_SNAKE_LEN);i++)
    {

        for(j=0;j<STATE_LEN;j++)
        {
            if(ch == P_SNAKE[i][j])
            {
                /*Hey i am just as disgusted as you are*/
                dir = (E_DIRE)j;
            }
        }
    }

    return dir;
}


void destroySnakeNode(void* snode)
{
    free((SnakeNode*)snode);
}

void getSNodeCoord(int* r, int* c,void* sn)
{
    *r = ((SnakeNode*)sn)->row;
    *c = ((SnakeNode*)sn)->col;  
}

void setSNodeCoordAndDir(int r, int c, E_DIRE d,SnakeNode* sn)
{
    sn->row = r;
    sn->col = c;
    sn->dir = d;
}

