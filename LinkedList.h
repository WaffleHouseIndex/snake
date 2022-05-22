/*Generic Linked List Standard Implementation*/
/*Source: https://curtin-ucp.gitbook.io/faq/06-structs */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef void (*listFunc)(void* data);

typedef struct LinkedListNode
{
	void* pData;
	struct LinkedListNode* pNext;
} LinkedListNode;

typedef struct LinkedList
{
	LinkedListNode* pHead;
	LinkedListNode* pTail;
	int iSize;	
} LinkedList;

LinkedList* createLinkedList();
void insertLast(LinkedList* list, void* entry);
void* removeLast(LinkedList* list);
void printLinkedList(LinkedList* list, listFunc funcPtr);
void freeLinkedList(LinkedList* list, listFunc funcPtr);

#endif