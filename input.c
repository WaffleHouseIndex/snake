#include "input.h"
#include "map.h"
#include "terminal.h"
#include <stdio.h>

char getInput()
{
    char c;

    disableBuffer();
    scanf(" %c",&c);
    enableBuffer();

    return c;
}

int isValid(char c)
{
    int result;
    result = FALSE;

    if(c=='w'||c=='a'||c=='s'||c=='d')
    {
        result = TRUE;
    }

    return result;
}