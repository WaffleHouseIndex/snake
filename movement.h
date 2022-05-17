#ifndef MOVEMENT_H
#define MOVEMENT_H


void move(char*** map,SNEK_BLOK** snek,int m_rows,int m_cols,int len_snek,char inp);
int isValidMove(int* move_r, int* move_c,char*** map, SNEK_BLOK** snek,int len_snek);

#endif