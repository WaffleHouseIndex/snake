/*Generic Linked List Standard Implementation*/
/*Source: https://curtin-ucp.gitbook.io/faq/06-structs */
/**/


#include <stdlib.h>
#include <assert.h>
#include "LinkedList.h"

LinkedList* createLinkedList()
{	
	LinkedList* pLinkedList = (LinkedList*) malloc(sizeof(LinkedList));
	pLinkedList->pHead = NULL;
	pLinkedList->pTail = NULL;
	pLinkedList->iSize = 0;

	return pLinkedList;	
}

/*Added below code, based off of insertLast*/
void insertStart(LinkedList* pList, void* pEntry)
{
	/* Create a new node */
	LinkedListNode* pNode = (LinkedListNode*) malloc (sizeof(LinkedListNode));
	pNode->pData = pEntry;
	pNode->pNext = NULL;
		
	/* If linkedlist is empty */
	if (pList->pHead == NULL)
	{
		assert(pList->pTail == NULL && pList->iSize == 0);		
		pList->pHead = pNode;
		pList->pTail = pNode;
	}
	else
	{
		assert(pList->pHead && pList->iSize > 0);

		pNode->pNext = pList->pHead;

		pList->pHead = pNode;
	}
	
	(pList->iSize)++;
}

/*End addition*/

void insertLast(LinkedList* pList, void* pEntry)
{
	/* Create a new node */
	LinkedListNode* pNode = (LinkedListNode*) malloc (sizeof(LinkedListNode));
	pNode->pData = pEntry;
	pNode->pNext = NULL;
		
	/* If linkedlist is empty */
	if (pList->pHead == NULL)
	{
		assert(pList->pTail == NULL && pList->iSize == 0);		
		pList->pHead = pNode;
	}
	else
	{
		assert(pList->pTail && pList->iSize > 0);	
		pList->pTail->pNext = pNode;
	}
	
	pList->pTail = pNode;
	(pList->iSize)++;
	
}

void* removeLast(LinkedList* pList) 
{ 
	LinkedListNode* pCur = pList->pHead;
	void* pRet = NULL;
	
	while (pCur)
	{		
		if (pCur->pNext == pList->pTail)
		{  /* If linkedlist has more than 1 node */
			
			/* TODO: set pRet = pTail's pData */
            pRet = pList->pTail->pData;
			/* TODO: NULLIFY all fields in pTail */
            pList->pTail->pData = NULL;
            pList->pTail->pNext = NULL;
			/* TODO: free pTail */
            free(pList->pTail);
			/* TODO: set pTail = pCur */
            pList->pTail = pCur;
			/* TODO: set pTail->pNext = NULL */
            pList->pTail->pNext = NULL;

			(pList->iSize)--;
			pCur = NULL;
			
			assert(pList->pTail && pList->pHead && pList->iSize > 0);
			
		}
		else if (pList->pHead == pList->pTail)
		{
			/* TODO: set pRet = pTail's pData */
            pRet = pList->pTail->pData;
			/* TODO: NULLIFY all fields in pTail */
            pList->pTail->pData=NULL;
            pList->pTail->pNext=NULL;
			/* TODO: free pTail */
            free(pList->pTail);
			/* TODO: set pTail = pHead = NULL */
            pList->pTail=NULL;
            pList->pHead=NULL;

			(pList->iSize)--;
			pCur = NULL;
			
			assert(pList->pTail == NULL && pList->pHead == NULL && pList->iSize == 0);
			
		}
		else
		{
			pCur = pCur->pNext;
		}		
	}
	
	return pRet;
}



void printLinkedList(LinkedList* pList, listFunc funcPtr)
{
	LinkedListNode* pCur = pList->pHead;
	
	while (pCur)
	{
		(*funcPtr)(pCur->pData);
		pCur = pCur->pNext;
	}
}

void freeLinkedList(LinkedList* pList, listFunc funcPtr) 
{
	LinkedListNode* pCur = pList->pHead;
	LinkedListNode* pTemp;
	
	while (pCur)
	{
		/* take pCur->pNext to pTemp */
		pTemp = pCur->pNext;
		
		/* clean pCur */
		(*funcPtr)(pCur->pData);
		pCur->pData = NULL;
		pCur->pNext = NULL;
		free(pCur);
		
		/* set pCur = pTemp */
		pCur = pTemp;		
	}	
	
	free(pList);
}
