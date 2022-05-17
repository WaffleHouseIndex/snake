#include "movement.h"
#include "snake.h"
#include "map.h"
#include "mem.h"

/*  Moves snek with input char {w,a,s,d}, 
    input should already be checked to before */
void move(char*** map,SNEK_BLOK** snek,int m_rows,int m_cols,int len_snek,char inp)
{    
    int move_r;
    int move_c;
    Dire move_d;

    /*Clear Snek off map*/
    clearSnek(map,snek,m_rows,m_cols,len_snek);

    /*Put Head of Snek coords in move_d,move_r & move_c*/
    getBlokCoords(&move_r,&move_c,I_HEAD,snek,len_snek);

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
    if(isValidMove(&move_r,&move_c,map,snek,len_snek))
    {
        moveSnek(move_r,move_c,move_d,snek,len_snek);
    }
}




/*Checks if a valid move returns TRUE if it is*/
int isValidMove(int* move_r, int* move_c,char*** map,
SNEK_BLOK** snek,int len_snek)
{
    /*Is not valid if:
        - Is a border move
        - move back into itself hence its second piece
    */

    int result;
    int BLOK_TWO_r,BLOK_TWO_c;

    result = TRUE;

    /*Get Coords of BLOK_TWO into vars*/
    getBlokCoords(&BLOK_TWO_r,&BLOK_TWO_c,I_TWO,snek,len_snek);

    if(isObj(map,*move_r,*move_c,BORDER_SYM))
    {
        result = FALSE;
    }
    else if(*move_r==BLOK_TWO_r && *move_c==BLOK_TWO_c)
    {
        result = FALSE;
    }

    return result;
}

