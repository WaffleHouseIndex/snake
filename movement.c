#include <string.h>
#include <stdlib.h>
#include "stdio.h"

#include "mem.h"
#include "snake.h"
#include "map.h"
#include "constants.h"
#include "movement.h"

/*  Moves snek with input char {w,a,s,d}, 
    input should already be checked to before */
void move(char** arr_map,NODE* snake_head,char inp)
{  
    int move_r;
    int move_c;
    E_DIRE move_d;


    /*Clear Snek off map*/
    clearSnake(arr_map,snake_head);

    /*Put Head of Snek coords in move_d,move_r & move_c*/
    getSNodeCoord(&move_r,&move_c,snake_head->data);

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
    
    /*Check Validity and move snek*/
    if(isValidMove(&move_r,&move_c,arr_map,snake_head))
    {
        moveSnake(move_r,move_c,move_d,snake_head);
    }
}

/*
    Moves the snek by moving snek "blok" status down the head to tail (down the linked list)
    Hence, moving the snek.
    The 2nd "blok" becomes the r,c,d of the head, then 3rd becomes...etc
*/
void moveSnake(int move_r,int move_c,E_DIRE move_d,NODE* snake_head)
{
    NODE* nextNode;
    S_SNODE* snode = (S_SNODE*)(snake_head->data);
    nextNode = snake_head->next;


    if(nextNode != NULL)
    {
        moveSnake(snode->row,snode->col,snode->dir,nextNode);
    }

    setSNodeCoordAndDir(move_r,move_c,move_d,(S_SNODE*)(snake_head->data));
    
}




/*Checks if a valid move returns TRUE if it is*/
int isValidMove(int* move_r, int* move_c,char** arr_map,NODE* snake_head)
{
    /*Is not valid if:
        - Is a border move
        - move back into itself hence its second piece
    */

    int result;
    int BLOK_TWO_r,BLOK_TWO_c;

    result = TRUE;

    /*Get Coords of BLOK_TWO into vars*/
    getSNodeCoord(&BLOK_TWO_r,&BLOK_TWO_c,getNthItem(NTH_BLOKTWO,snake_head)->data);

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


