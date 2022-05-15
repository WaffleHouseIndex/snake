#include "main.h"
#include "constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

    /*
        Start of Snek game

        1. Parse cmdline args 
           - Format argv = [snek,filename,<col_map>,<len_snek>]  
        2. Validate cmdline args
           - must have 4 args snek,<row_map>,<col_map>,<len_snek>
           - row_map, col_map, len_snek must be over 0 
           - len_snek must be at most [(row_map)*(col_map)] - 1
        3. If valid start game with parameters else end program
    */

    int amountOfFoodToWin; 
    char* filename;
   
    if (argc != ARG_COUNT) 
    {
        printf("Usage: ./snake <filename> <food_amount_to_win>\n");
    }
    else
    {
        /*Under the assumption of correct datatypes*/
        amountOfFoodToWin = atoi(argv[I_FOOD_AMOUNT_TO_WIN]);
        

        if(row_map>MIN_ROW_MAP)
        {
            if(col_map>MIN_COL_MAP)
            {
                if(len_snek>=MIN_LEN_SNEK && len_snek<=col_map)
                {
                    /*Initalise Game*/
                    runGame(row_map,col_map,len_snek);
                }
                else
                {
                    printf("Invalid parameter <len_snek>. Should be over 3 and not more than <col_map>\n");
                }
            }
            else
            {
                printf("Invalid parameter <col_map>. Should be over 5.\n");
            }
        }
        else
        {
            printf("Invalid parameter <row_map>. Should be over 5.\n");
        }
    }


    return 0;
}