#ifndef H_MEM
#define H_MEM

/*Node struct definition for generic linked list*/
typedef struct 
{
    void* data;
    struct NODE* next;
}NODE; 

NODE* initEmptyNode();

#endif