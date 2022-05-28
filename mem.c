#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "mem.h"

/*
Extra linked list functions
*/

/*Takes in linkedlist head and returns the nth element
    or if it reaches end of LL first will return NULL*/
LinkedListNode* getNthItem(int n, LinkedList* snake)
{
    int i;
    LinkedListNode* node;

    /*Start at first element*/
    node = snake->pHead;

    /*Walk down list stop once at the nth element*/
    /*If you reach null first end loop and return NULL*/
    for (i = 1; i < n; i++)
    {
        if(node->pNext == NULL)
        {
            node = NULL;
            i=n;
        }
        else
        {
            node = node->pNext;
        }
    }
    
    return node;
}





