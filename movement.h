#ifndef MOVEMENT_H
#define MOVEMENT_H

int move(char** arr_map,LinkedList* snake,char inp);
int isValidMove(int* move_r, int* move_c,char** arr_map,LinkedList* snake);
void moveSnake(int move_r,int move_c,E_DIRE move_d,LinkedListNode* snakeHead);

#endif