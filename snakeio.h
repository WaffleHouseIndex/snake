#ifndef H_SNAKEIO
#define H_SNAKEIO

#define EOF -1

FILE* initFile(char* filename);
void parseMapSize(FILE* fptr,int* r,int* c);
void parseSnake(FILE* ptr,NODE* snake_head);

#endif