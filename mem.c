#include "mem.h"
#include <string.h>
#include <stdlib.h>


/*
Memory manipulation of linked list
*/


/*
The linked list will store the next node and a void* data
Data will have a pointer to a struct

*/
NODE* initEmptyNode()
{
    return (NODE*)malloc(sizeof(NODE));
}

void pushNode(NODE* head_node,NODE* new_node)
{
    /*Point new node to head*/
    new_node->next = head_node;

    /*now head_node is new_node*/
    *head_node = *new_node;

}

void appendNode()
{

}


