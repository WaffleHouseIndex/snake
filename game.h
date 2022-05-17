#ifndef H_GAME
#define H_GAME

#include "mem.h"
#include "map.h"

typedef struct
{
    unsigned int amountOfFoodToWin;
    S_MAP* Map; 
    NODE* snake_head;
}S_GAME;

typedef enum {STOPPED,RUNNING}S;


S_GAME* initGame(char* filename, int amountOfFoodToWin);
void runGame(S_GAME* game);
S_GAME* createEmptyGameStruct();
void destroyGame(S_GAME* game);

#endif