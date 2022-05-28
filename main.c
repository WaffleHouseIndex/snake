#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "LinkedList.h"
#include "map.h"
#include "game.h"
#include "constants.h"
#include "main.h"


int main(int argc, char* argv[])
{

    /*
        Start of Snek game

        1. Parse cmdline args 
           - Format argv = [snake,filename,<food amount to win>]  
        2. Validate cmdline args
           - must have 3 args 
           - row_map, col_map, len_snek must be over constant value [constants.h] 
           - len_snek must be at most [(row_map)*(col_map)] - 1
        3. If valid start game with parameters else end program
    */

    int amountOfFoodToWin; 
    char* filename;
    S_GAME* snakeGame;

    if (argc != ARG_COUNT) 
    {
        printf("Usage: ./snake <filename> <food_amount_to_win>\n");
    }
    else
    {
        /*Under the assumption of correct datatypes*/
        filename = argv[I_SNAKE_FILENAME];
        amountOfFoodToWin = atoi(argv[I_FOOD_AMOUNT_TO_WIN]);


        if(amountOfFoodToWin>=MIN_FOOD_AMOUNT_TO_WIN)
        {
            
            /***********************************************/
            snakeGame = initGame(filename,amountOfFoodToWin);


            if(snakeGame!=NULL)
            {


                /******************/
                runGame(snakeGame);


                /******************/
                destroyGame(snakeGame);

            }

        }
        else
        {
            printf("Invalid amountOfFoodToWin. Should be >= %d.\n",MIN_FOOD_AMOUNT_TO_WIN);
        }
        
    }



    return 0;
}