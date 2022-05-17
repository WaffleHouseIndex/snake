
#include "snake.h"
#include <stdlib.h>

/*Contains snake game specific functions*/


/*
Takes in row,col and ch
Returns a a snake node ptr.
If an error occurs will return a NULL ptr
*/
S_SNODE* initSnakeNodeWithCh(int row,int col, char ch)
{
    E_DIRE dir;
    S_SNODE* newSnakeNode;

    dir = getChToDirEnum(ch);

    /*Check if a valid dir*/
    if(dir != E_NULL)
    {
        newSnakeNode = initSnakeNodeWithDir(row,col,dir);
    }

    return newSnakeNode;
}

S_SNODE* initSnakeNodeWithDir(int row,int col, E_DIRE dir)
{
    S_SNODE* newSnakeNode;
    newSnakeNode = initEmptySnakeNode();
    newSnakeNode->row = row;
    newSnakeNode->col = col;
    newSnakeNode->dir = dir;
    return newSnakeNode;
}

S_SNODE* initEmptySnakeNode()
{
    return (S_SNODE*)malloc(sizeof(S_SNODE));
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


void destroySNode(void* snode)
{
    free((S_SNODE*)snode);
}

void getSNodeCoord(int* r, int* c,void* sn)
{
    *r = ((S_SNODE*)sn)->row;
    *c = ((S_SNODE*)sn)->col;  
}

void setSNodeCoordAndDir(int r, int c, E_DIRE d,S_SNODE* sn)
{
    sn->row = r;
    sn->col = c;
    sn->dir = d;
}

