#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "mem.h"
#include "snake.h"
#include "constants.h"

/*
Memory manipulation of linked list

The linked list will store the next node and a void* data
Data will have a pointer to a point in memory, could be NULL

*/
NODE* initEmptyNode()
{
    NODE* newNode;
    newNode = (NODE*)malloc(sizeof(NODE));

    newNode->data = NULL;
    newNode->next = NULL;
    newNode->destroyData = NULL;

    return newNode;
}

NODE* initNodeWithData(void* d)
{
    NODE* newNode = initEmptyNode();
    newNode->data = d;
    return newNode;
}
NODE* initNodeWithDataWithDestroyFunc(void* d,void (*destroyData)(void*))
{
    NODE* newNode = initNodeWithData(d);
    newNode->destroyData = destroyData;
    return newNode;
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

/*Takes in linkedlist head and returns the nth element
    or if it reaches end of LL first will return NULL*/
NODE* getNthItem(int n, NODE* head)
{
    int i,cont;
    NODE* node;


    /*Start at first element*/
    i=1;
    cont = TRUE;
    node = head;

    
    do
    {
        if(i==n)
        {
            cont = FALSE;
        }
        else if(node->next == NULL)
        {
            cont = FALSE;
            node = NULL;
        }
        else
        {
            node = node->next;
            i++;
        }

    } while (cont);

    return node;
    
}


/*Must feed it the head of linked list or else will partially destroy linkedlist*/
void destroyLinkedList(NODE* n)
{
   backIterFuncLinkedList(n,destroyNode);
}

/*Simple iterators forward and backward, calling a void functional pointer with NODE* type*/
void backIterFuncLinkedList(NODE* n,void(*func)(NODE*))
{
    if(n->next != NULL)
    {
        backIterFuncLinkedList(n->next,func);
    }

    func(n);
}

void iterFuncLinkedList(NODE* n,void(*func)(NODE*))
{
    func(n);

    if(n->next!=NULL)
    {
        iterFuncLinkedList(n->next,func);
    }
}




