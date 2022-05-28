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

    char** arr_map;
}S_MAP;


S_MAP* initEmptyMapStruct();
S_MAP* initMap(int r, int c);
void destroyMap(S_MAP* s_map);
char** initEmptyMapArray(int m_rows, int m_cols);


void updateMap(S_MAP* Map, int r, int c, char ch);

void spawnBorder(S_MAP* s_map);
void spawnSnake(S_MAP* Map,LinkedList* snake);
void spawnSnakeFromNode(S_MAP* Map,LinkedList* snake,LinkedListNode* n);
void spawnFood(S_MAP* Map);

void clearSnake(char** arr_map,LinkedListNode* snakeHead);

int isObj(char** map,int r,int c,char obj);
int isValidMap(int m_row,int m_col);

#endif