

/*
    Map struct will be passed around 
    Holding the size of the map including '*' border
    Hence, playable size is size_row, size_col - 2
*/

typedef struct 
{
    unsigned int size_row;
    unsigned int size_col;

    char*** map;
}S_MAP;

