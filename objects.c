/*Manages iteractions between elements such as border, snake and food*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "snake.h"
#include "map.h"
#include "constants.h"
#include "objects.h"



void checkCollisions(int* isFoodEaten,int* isPlayerDead,S_MAP* Map,LinkedListNode* snakeHead)
{
    /*Check head position against food*/
    int head_r, head_c;

    /*(in pompous tone) ISO C90 forbids mixed declarations and code*/
    #ifndef UNBEATABLE
    LinkedListNode* nextNode;
    #endif

    SnakeNode* snakeNode;
    snakeNode = (SnakeNode*)(snakeHead->pData);

    head_r = snakeNode->row;
    head_c = snakeNode->col;

    if(isObj(Map->arr_map,head_r,head_c,FOOD_SYM))
    {
        *isFoodEaten = TRUE;
    }

    /*Check head position, against other snake pieces, skipping the head of course!
        Obviously only the head could collide with itself if UNBEATABLE isn't in effect
        If they are equal it has collided, hence isPlayerDead is set to TRUE*/

    
    #ifndef UNBEATABLE
    nextNode = snakeHead->pNext;
    while (nextNode != NULL)
    {
        snakeNode = (SnakeNode*)(nextNode->pData);
        if(snakeNode->row == head_r && snakeNode->col == head_c)
        {
            *isPlayerDead = TRUE;
        }

        nextNode = nextNode->pNext;
    }
    #endif
    
}

