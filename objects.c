/*Manages iteractions between elements such as border, snake and food*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mem.h"
#include "snake.h"
#include "map.h"
#include "objects.h"
#include "constants.h"


void checkCollisions(int* foodEaten,int* isPlayerDead,S_MAP* Map,NODE* snake_head)
{
    /*Check head position against food*/
    int head_r, head_c;
    NODE* nextNode;

    S_SNODE* snakeNode;
    snakeNode = (S_SNODE*)(snake_head->data);

    head_r = snakeNode->row;
    head_c = snakeNode->col;

    if(isObj(Map->arr_map,head_r,head_c,FOOD_SYM))
    {
        (*foodEaten)++;

        spawnFood(Map);
    }

    /*Check head position, against other snake pieces, skipping the head of course!
        Obviously only the head could collide with itself if UNBEATABLE isn't in effect
        If they are equal it has collided, hence isPlayerDead is set to TRUE*/
    #ifndef UNBEATABLE
    nextNode = snake_head->next;
    while (nextNode != NULL)
    {
        snakeNode = (S_SNODE*)(nextNode->data);
        if(snakeNode->row == head_r && snakeNode->col == head_c)
        {
            *isPlayerDead = TRUE;
        }

        nextNode = nextNode->next;
    }
    #endif
    
}

