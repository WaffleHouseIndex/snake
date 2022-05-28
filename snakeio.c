#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "snake.h"
#include "constants.h"
#include "snakeio.h"


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
If it fails to read the ints r and c will be INT_ERROR
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
        *r = INT_ERROR;
        *c = INT_ERROR;
        if(ferror(fptr))
        {
            perror("Error reading file. File may be corrupted.: ");
        }
    }
}


/*
******MUST BE CALLED AFTER PARSEMAPSIZE*******

Takes in a FILE* and pointer to a pointer to the head NODE
Calls functions from mem.c to create linked list as it reads file
If it completes a snake will put a pointer in ptr_snake else
ptr_snake will be a nullptr

FYI
ptr_snake is pointer to a linkedlist node stored elsewhere 
but is updated elsewhere via pushNode in mem.c
*/
void parseSnake(FILE* fptr,LinkedList** ptr_snake)
{
    int nRead;
    int r,c;
    char ch;

    SnakeNode* newSnakeNode;

    do
    {
        nRead = fscanf(fptr,"%d %d %c",&r,&c,&ch);

        /*Should successfully read 3 things
            row, col and a character
        */
        if(nRead == 3)
        {
            /*
            Each line create a SnakeNode, insert to the start of LinkedList snake.
            Try create a snake struct using read values
             It is assumed that r and c are valid if read properly

             then push to front of linked list and update head

             r+1 and c+1, to put coords in reference with actual map size 
            */

            newSnakeNode = initSnakeNodeWithCh((r+1),(c+1),ch);

            /*Check for problems*/
            if(newSnakeNode != NULL)
            {
                /*Now insert at the start of linked list*/
                insertStart(*ptr_snake,(void*)newSnakeNode);
            }
            else
            {
                /*Don't continue as an error has occurred*/
                nRead = EOF;

                /*Destroy snake*/
                freeLinkedList(*ptr_snake,destroySnakeNode);

                *ptr_snake = NULL; 
                
            }
            
        }
        else
        {
            *ptr_snake = NULL;
            nRead = EOF;
        }

    }while(nRead!=EOF);
}



