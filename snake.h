#ifndef H_SNAKE
#define H_SNAKE

typedef enum DIRECTION{UP,DOWN,LEFT,RIGHT}E_DIRE;

#define STATE_LEN 4
const char SNAKE_H[STATE_LEN] = {'^','v','<','>'};
const char SNAKE_B[STATE_LEN] = {'|','|','-','-'};
const char SNAKE_T[STATE_LEN] = {'#','#','#','#'};

#define P_SNAKE_LEN 3
const char** P_SNAKE[P_SNAKE_LEN] = {&SNAKE_H,&SNAKE_B,&SNAKE_T};

typedef struct
{
    int row;
    int col;
    E_DIRE dir; 
}S_SNODE;

void iterFuncLinkedList(NODE* n,void(*func)(void*));
S_SNODE* initSnakeNode(int row,int col, char ch);
S_SNODE* initEmptySnakeNode();
E_DIRE getChToDirEnum(char ch);
void destroySNode(S_SNODE* snode);

#endif
