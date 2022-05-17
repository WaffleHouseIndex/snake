#ifndef MOVEMENT_H
#define MOVEMENT_H

void move(char** arr_map,NODE* snake_head,char inp);
int isValidMove(int* move_r, int* move_c,char** arr_map,NODE* snake_head);
void moveSnake(int move_r,int move_c,E_DIRE move_d,NODE* snake_head);

#endif