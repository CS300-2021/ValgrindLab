/****************************************************************************
 File name:  	dynamicList.c
 Author:     	$Author: chadd $
 Date:       	$Date: 2011-10-31 08:27:24 -0700 (Mon, 31 Oct 2011) $
 Class:				CS300
 Assignment:	In Class Valgrind Lab
 Purpose:			Practice finding memory errors with Valgrind
 	 	 	 	 	 	  This code is seeded with ERRORS!
 RevisionID: 	$Id: dynamicList.c 12 2011-10-31 15:27:24Z chadd $
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*
 * the node for the Linked List.
 */
typedef struct IntNode* IntNodePtr;

typedef struct IntNode
{
	int value;
	IntNodePtr psNext;
} IntNode;


/****************************************************************************
 Function: 	 		createList

 Description: 	create the entire list and set the head pointer

 Parameters:		psHead - a handle to the head of the list

 Returned:	 		none
 ****************************************************************************/
void createList(IntNodePtr * hsHead)
{
	// pass a handle!
	IntNodePtr psCurrent;
	int counter = 1;
	int i;

	*hsHead = (IntNodePtr) malloc(sizeof(IntNode)); // ERROR IntNodePtr
	psCurrent = hsHead;

	for(i=0;i< 6;++i)
	{

		psCurrent->value = counter;

		counter += counter + i*3;

		psCurrent->psNext = (IntNodePtr) malloc(sizeof(IntNode));
		psCurrent = psCurrent->psNext;

		// set the last node in the list to zero
		psCurrent->value = 0;
	}
	psCurrent->psNext = NULL;

}



/****************************************************************************
 Function: 	 		printList

 Description: 	print every integer in the list on a single line, each int
								separated by a space

 Parameters:		psHead - the head of the list

 Returned:	 		none
 ****************************************************************************/
void printList(IntNodePtr psHead)
{
	// pass a pointer
	IntNode *psCurrent = psHead;
	int i;

	for( i = 0; psHead && psCurrent->psNext ; i++)
	{
		printf(" %d", psCurrent->value);
		psCurrent = psCurrent->psNext;
	}
	printf("\n");
}


/****************************************************************************
 Function: 	 		freeEntireList

 Description: 	free the entire list and set the head pointer to NULL

 Parameters:		psHead - a handle to the head of the list

 Returned:	 		none
 ****************************************************************************/
void freeEntireList(IntNodePtr * hsHead)
{
	// pass a handle!
	IntNodePtr psCurrent = *hsHead;
	IntNodePtr psNext;

	while( psCurrent )
	{
		free(psCurrent);
		psNext = psCurrent->psNext;

		psCurrent = psNext;
	}
	hsHead = NULL;
}

/****************************************************************************
 Function: 	 		main

 Description: 	main driver to exercise the above functions.

 Parameters:		none
 Returned:	 		none
 ****************************************************************************/
int main()
{
	int number;
	int size;
	int i;

	IntNodePtr psHead = NULL; // the head of the linked list
	IntNodePtr psCurrent = NULL;
	IntNodePtr psPrev = NULL;
	IntNodePtr psNext = NULL;

	createList(&psHead);


	// print all the integers to the screen
	// all on one line, separated by a space
	printf("Entire List: ");
	printList(psHead);

	// free the List!
	freeEntireList(&psHead);

	// print all the integers to the screen
	// all on one line, separated by a space
	printf("Empty List: ");
	printList(psHead);

	return EXIT_SUCCESS;
}
