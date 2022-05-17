#ifndef H_SNAKE
#define H_SNAKE

typedef enum DIRECTION{UP,DOWN,LEFT,RIGHT,E_NULL}E_DIRE;

#define STATE_LEN 4
static const char SNAKE_H[STATE_LEN] = {'^','v','<','>'};
static const char SNAKE_B[STATE_LEN] = {'|','|','-','-'};
static const char SNAKE_T[STATE_LEN] = {'#','#','#','#'};

#define P_SNAKE_LEN 3
static const char* P_SNAKE[P_SNAKE_LEN] = {SNAKE_H,SNAKE_B,SNAKE_T};

typedef struct
{
    int row;
    int col;
    E_DIRE dir; 
}S_SNODE;


S_SNODE* initSnakeNodeWithCh(int row,int col, char ch);
S_SNODE* initSnakeNodeWithDir(int row,int col, E_DIRE dir);
S_SNODE* initEmptySnakeNode();
E_DIRE getChToDirEnum(char ch);
void destroySNode(void* snode);

#endif
