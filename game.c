#include "map.h"
#include "snake.h"
#include "mem.h"
#include "game.h"
#include "constants.h"
#include "snakeio.h"
#include "random.h"
#include "output.h"

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
    /*Start Random*/
    initRandom();

    /*Open file and check for errors*/
    S_GAME* game;

    int r,c;
    S_MAP* map;

    NODE* snake_head;

    map = NULL;
    game = NULL; 
    snake_head = NULL;

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
                parseSnake(fptr,&snake_head);
                if(snake_head!=NULL)
                {
                    game = createEmptyGameStruct();
                    game->amountOfFoodToWin = amountOfFoodToWin;
                    game->Map = map;
                    game->snake_head = snake_head;

                }
                else
                {
                    printf("Invalid snake.");
                }

            }
        }
        
        
    }

    /*We are now finished with the file*/
    close(fptr);

    return game;
}










/*
Takes in a valid game and starts gameloop
*/
void runGame(S_GAME* game)
{
    S status;
    int isGameBeaten;
    int isPlayerDead;

    int amountOfFoodEaten;
    amountOfFoodEaten = 0;

    /*Spawn Snake*/
    spawnSnake(I_HEAD,game->Map,game->snake_head);

    /*Output Initial game status*/
    out_Map(game->Map);
    printf("Food Eaten: %d / %d",amountOfFoodEaten,game->amountOfFoodToWin);
    /*Game Loop*/
    status = STOPPED;
    isGameBeaten = FALSE;
    isPlayerDead = FALSE;

    while(status==RUNNING)
    {
       
    }
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
    destroyMap(game->Map);
    destroyLinkedList(game->snake_head);

    free(game);
}