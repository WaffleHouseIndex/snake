#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "snakeio.h"
#include "mem.h"



/*Reading formatted snake file*/

/*
    FORMAT
    <map_row> <map_col>
    <r> <c> <body>
    20 10
    0 0 #
    1 0 |
    2 0 V
*/


/*
Takes in a FILE* and pointers to row and col variables
Reads the first line of given file  
If it fails to read the ints r and c will be null
*/
void parseMapSize(FILE* fptr,int* r,int* c)
{
    int nRead;

    /*In case it somehow moved from start of file*/
    rewind(fptr); 

    nRead = fscanf(fptr,"%d %d",r,c);
    /*fscanf should have read two ints*/
    if(nRead != 2)
    {
        /*An error must have occurred as it didnt read two ints*/
        *r = NULL;
        *c = NULL;
        if(ferror(fptr))
        {
            perror("Error reading file. File may be corrupted.");
        }

    }



}


/*
Takes in a FILE* and pointer to the NODE of the snake_head
Calls functions from mem.c to create linked list as it reads file
If it completes a snake will put a pointer in snake_head else
snake_head will be a nullptr
*/
void parseSnake(FILE* ptr,NODE* snake_head)
{

}



