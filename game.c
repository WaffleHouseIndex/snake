#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mem.h"
#include "LinkedList.h"
#include "snake.h"
#include "map.h"
#include "game.h"
#include "constants.h"
#include "snakeio.h"
#include "random.h"
#include "output.h"
#include "input.h"
#include "movement.h"
#include "objects.h"


/*
    Takes in filename and amountOfFoodToWin will 
    calls initMap and initSnake
    return a pointer to a game struct
    if an error occurred will return NULL
*/
S_GAME* initGame(char* filename, int amountOfFoodToWin)
{
    FILE* fptr;

    S_GAME* game;

    int r,c;
    S_MAP* map;

    LinkedList* snake;

    map = NULL;
    game = NULL; 
    snake = NULL;

    /*Start Random*/
    initRandom();

    /*Opens filestream and checks for errors*/
    fptr = fopen(filename,"r");


    if(fptr == NULL)
    {
        perror("Failed to open file: ");
    }
    else
    {
        /*With file open initialise a map*/
        parseMapSize(fptr,&r,&c);
        if(r == INT_ERROR || c == INT_ERROR)
        {
            printf("Invalid row and column type!\n");
        }
        else
        {
            map = initMap(r,c);

            if(map==NULL)
            {
                printf("Invalid map size.\n");
            }
            else
            {
                /*Just before parsing snake create the LinkedList struct*/
                snake = createLinkedList();
                
                /*If parseSnake has any problems will free snake*/
                parseSnake(fptr,&snake);

                if(snake!=NULL)
                {
                    /*Create game struct as everything is good to go*/
                    game = createEmptyGameStruct();
                    game->amountOfFoodToWin = amountOfFoodToWin;
                    game->Map = map;
                    game->snake = snake;

                }
                else
                {
                    destroyMap(map);
                    printf("Invalid snake.\n");
                }

            }
        }

        /*We are now finished with the file*/
        fclose(fptr);
        
    }


    return game;
}










/*
Takes in a valid game and starts gameloop
*/
void runGame(S_GAME* game)
{
    S status;

    
    int isFoodEaten;
    int amountOfFoodEaten;
    int isPlayerDead;
    
    status = RUNNING;
    isFoodEaten = FALSE;
    isPlayerDead = FALSE;
    amountOfFoodEaten = ZERO;

    /*Initial Spawning, order is crucial as spawnFood needs the snake on map*/
    spawnSnake(game->Map,game->snake);
    spawnFood(game->Map);

    /*Output Initial game status*/
    out_Map(game->Map);
    printf("Food Eaten: %d / %d\n",amountOfFoodEaten,game->amountOfFoodToWin);
    
    /*Game Loop*/
    while(status==RUNNING)
    {
        char inp = getInput();
        if(isValid(inp))
        {
            /*Move Snek*/
            move(game->Map->arr_map,&(game->snake->pHead),inp);

            /*Check for collision with body and food*/
            checkCollisions(&isFoodEaten,&isPlayerDead,game->Map,game->snake->pHead);

            /*Place Snek back on map*/
            spawnSnake(game->Map,game->snake);

            if(isFoodEaten)
            {
                amountOfFoodEaten++;
                if(amountOfFoodEaten == game->amountOfFoodToWin)
                {
                    printf("You've Won! :)\n");
                    status = STOPPED;
                }
                else
                {
                    spawnFood(game->Map);
                }
    
                isFoodEaten = FALSE;
            }
            
            out_Map(game->Map);
            printf("Food Eaten: %d / %d\n",amountOfFoodEaten,game->amountOfFoodToWin);
        }
        else
        {
            out_Map(game->Map);
            printf("Invalid Input.\n");
        }


        if(isPlayerDead)
        {
            printf("You've Died! ;(\n");
            status = STOPPED;
        }
        

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
    freeLinkedList(game->snake,destroySnakeNode);

    free(game);
}