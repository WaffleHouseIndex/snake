#include <string.h>
#include <stdlib.h>
#include "stdio.h"

#include "LinkedList.h"
#include "mem.h"
#include "snake.h"
#include "map.h"
#include "constants.h"
#include "movement.h"

/*  Moves snek with input char {w,a,s,d}, 
    input should already be checked to before */
void move(char** arr_map,LinkedList* snake,char inp)
{  
    int move_r;
    int move_c;
    E_DIRE move_d;


    /*Clear Snek off map*/
    clearSnake(arr_map,snake->pHead);

    /*Put Head of Snek coords in move_d,move_r & move_c*/
    getSNodeCoord(&move_r,&move_c,(snake->pHead)->pData);

    /*Change coords to move*/
    switch(inp)
    {
        case 'w':
            move_d = UP;
            move_r--;
            break;
        case 'a':
            move_d = LEFT;
            move_c--;
            break;
        case 's':
            move_d = DOWN;
            move_r++;
            break;
        case 'd':
            move_d = RIGHT;
            move_c++;
            break;
        default:
            break;

    }

    /*Check Validity and move snake*/
    if(isValidMove(&move_r,&move_c,arr_map,&(snake->pHead)))
    {
        /*Now check if the calculated move coincides that of food*/
        if(isObj(arr_map,move_r,move_c,FOOD_SYM))
        {
            /*It does so push a new node onto the snake with move_d,r,c*/
            
            pushNode(snake->pHead,initNodeWithDataWithDestroyFunc((void*)(initSnakeNodeWithDir(move_r,move_c,move_d)),destroySnakeNode));

            /*Collision will be detected later*/

        }
        else
        {
            moveSnake(move_r,move_c,move_d,&(snake->pHead));
        }
    }

    
    
    
    
}

/*
    Moves the snake moving snake node status down the head to tail (down the linked list)
    Hence, moving the snek.
    The 2nd snode becomes the r,c,d of the head, then 3rd becomes the 2nd...etc
*/
void moveSnake(int move_r,int move_c,E_DIRE move_d,LinkedListNode* snakeHead)
{
    LinkedListNode* nextNode;
    SnakeNode* snode = (SnakeNode*)(snakeHead->pData);
    nextNode = snakeHead->pNext;


    if(nextNode != NULL)
    {
        moveSnake(snode->row,snode->col,snode->dir,nextNode);
    }

    setSNodeCoordAndDir(move_r,move_c,move_d,(SnakeNode*)(snakeHead->pData));
    
}




/*Checks if a valid move returns TRUE if it is*/
int isValidMove(int* move_r, int* move_c,char** arr_map,LinkedList* snake)
{
    /*Is not valid if:
        - Is a border move
        - move back into itself hence its second piece
    */

    int result;
    int BLOK_TWO_r,BLOK_TWO_c;

    result = TRUE;

    /*Get Coords of BLOK_TWO into vars*/
    getSNodeCoord(&BLOK_TWO_r,&BLOK_TWO_c,getNthItem(NTH_BLOKTWO,snake)->pData);

    if(isObj(arr_map,*move_r,*move_c,BORDER_SYM))
    {
        result = FALSE;
    }
    else if(*move_r==BLOK_TWO_r && *move_c==BLOK_TWO_c)
    {
        result = FALSE;
    }

    return result;
}


