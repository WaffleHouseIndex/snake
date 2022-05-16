#ifndef H_GAME
#define H_GAME

typedef struct
{
    unsigned int amountOfFoodToWin;
    S_MAP* map; 
}S_GAME;

S_GAME* initGame(char* filename, int amountOfFoodToWin);
void runGame(S_GAME* game);

#endif