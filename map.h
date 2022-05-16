#ifndef H_MAP
#define H_MAP

#define FOOD_SYM '@'
#define EMPTY_SYM ' '
#define BORDER_SYM '*'


/*
    Map struct will be passed around 
    Holding the size of the map including '*' border
    Hence, playable size is size_row, size_col - 2
*/

typedef struct 
{
    unsigned int size_row;
    unsigned int size_col;

    char** map;
}S_MAP;


S_MAP* initMap(int r, int c);
S_MAP* initEmptyMapStruct();
char** initEmptyMapArray(int m_rows, int m_cols);

void spawnBorder(S_MAP* s_map);

/*To Change*/
void spawnFood(char*** map,int m_rows,int m_cols);
int isObj(char*** map,int r,int c,char obj);


#endif