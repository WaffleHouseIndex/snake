#ifndef H_MEM
#define H_MEM

/*Node struct definition for generic linked list*/
/*destroyData if not NULL, contains a function pointer to destroy
content of data
*/
typedef struct
{
    void* data;
    void (*destroyData)(void*);
    struct NODE* next;
}NODE; 
  

NODE* initEmptyNode();
void pushNode(NODE** ptr_headNode,NODE* newNode)
void destroyLinkedList(NODE* n);
void destroyNode(NODE* n)

#endif