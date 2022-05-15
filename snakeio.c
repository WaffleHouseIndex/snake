#include "snakeio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Reading and Writing to snake file*/

/*
    FORMAT
    <map_row> <map_col>
    <r> <c> <body>
    20 10
    0 0 #
    1 0 |
    2 0 V
*/

void parse
