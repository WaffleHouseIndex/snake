#ifndef H_SNAKEIO
#define H_SNAKEIO


FILE* initFile(char* filename);
void parseMapSize(FILE* fptr,int* r,int* c);
void parseSnake(FILE* fptr,NODE** ptr_headNode);

#endif