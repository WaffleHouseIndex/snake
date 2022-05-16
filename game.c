#include "map.h"
#include "game.h"
#include "constants.h"
#include "snakeio.h"

#include <stdlib.h>
#include <stdio.h>

/*
    Takes in filename and amountOfFoodToWin will 
    calls initMap and initSnake
    return a pointer to a game struct
    if an error occurred will return NULL
*/
S_GAME* initGame(char* filename, int amountOfFoodToWin)
{
    /*Open file and check for errors*/
    S_GAME* game;

    int r,c;
    S_MAP* map;

    map = NULL;
    game = NULL; 

    /*Opens filestream and checks for errors*/
    FILE* fptr;
    fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
        perror(("Failed to open %s",filename));
    }
    else
    {
        /*With file open initialise a map*/
        parseMapSize(fptr,&r,&c);
        if(r == NULL || c == NULL)
        {
            printf("Failed to initialise game!");
        }
        else
        {
            map = initMap(r,c);
            if(map==NULL)
            {
                printf("Invalid map size.");
            }
            else
            {
                game = createEmptyGameStruct();
                game->amountOfFoodToWin = amountOfFoodToWin;
                game->map = map;
            }
        }
        
        
    }

    

    return game;
}


/*
Takes in a valid game and starts gameloop
*/
void runGame(S_GAME* game)
{

}

/*
Game Struct
*/
S_GAME* createEmptyGameStruct()
{
    return (S_GAME*)malloc(sizeof(S_GAME));
}

void destroyGame(S_GAME* game)
{
    
}