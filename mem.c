#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "mem.h"
#include "snake.h"
#include "map.h"
#include "output.h"


/*
Memory manipulation of linked list
*/



/*  ************Generic********** */

/*
The linked list will store the next node and a void* data
Data will have a pointer to a struct

*/
NODE* initEmptyNode()
{
    return (NODE*)malloc(sizeof(NODE));
}

/*Takes in a pointer to the head of linked list
    Then places new node onto the head 
    
    CAREFUL!!
    Side effect: headNode is then set to newNode*/
void pushNode(NODE** ptr_headNode,NODE* newNode)
{
    /*Point new node to head*/
    newNode->next = *ptr_headNode;

    /*now head_node is new_node*/
    *ptr_headNode = newNode;

}


void destroyNode(NODE* n)
{
    /*If it has a destroyData function call it with data*/
    if(n->destroyData != NULL)
    {
        (*(n->destroyData))(n->data);
    }

    /*Then destroy the node itself*/
    free(n);

}


/*Must feed it the head of linked list or else will partially destroy linkedlist*/
void destroyLinkedList(NODE* n)
{
    NODE* nextNode;
    nextNode = n->next;

    if(nextNode != NULL)
    {
        destroyLinkedList(nextNode);
    }

    destroyNode(n);
}

/*Iterates a through linked from node 'n' and calls 'func' with that given nodes data*/
void backIterFuncLinkedList(NODE* n,void(*func)(NODE*))
{
    if(n != NULL)
    {
        backIterFuncLinkedList(n->next,func);
    }

    func(n->data);
}

void iterFuncLinkedList(NODE* n,void(*func)(NODE*))
{
    func(n->data);

    if(n->next!=NULL)
    {
        iterFuncLinkedList(n->next,func);
    }
}




