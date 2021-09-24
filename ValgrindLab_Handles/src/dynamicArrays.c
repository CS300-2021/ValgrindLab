/****************************************************************************
 File name:  	dynamicArrays.c
 Author:     	chadd
 Date:       	June 17, 2019
 Class:				CS300
 Assignment:	In Class Valgrind Handles Lab
 Purpose:			Practice finding memory errors with Valgrind
 	 	 	 	 	 	  This code is seeded with ERRORS!

****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
 Function: 	 		printSizes

 Description: 	This function prints to the screen the size of primitive types

 Parameters:		None

 Returned:			None
 ****************************************************************************/
void printSizes()
{
	printf("\nSizeof(int) : %d\n", sizeof(int));
	printf("Sizeof(short) : %d\n", sizeof(short));
	printf("Sizeof(long) : %d\n", sizeof(long));
	printf("Sizeof(long long) : %d\n", sizeof(long long));

	printf("Sizeof(char) : %d\n", sizeof(char));
	printf("Sizeof(float) : %d\n", sizeof(float));
	printf("Sizeof(double) : %d\n", sizeof(double));
	printf("Sizeof(int*) : %d\n", sizeof(int*));
	printf("Sizeof(char*) : %d\n", sizeof(char*));
}

/****************************************************************************
 Function: 	 		expand

 Description: 	reallocate a larger array, and copy the data from the smaller
 	 	 	 	 	 	 	 	array into the larger array.  the empty spots in the larger
 	 	 	 	 	 	 	 	array are filled with -42.  The original, smaller array must
 	 	 	 	 	 	 	 	be deallocated in this function.

 Parameters:		pArray - the handle to the array
								size - the size of the array
								newSize - the size of the new array
 Returned:	 		none
 ****************************************************************************/
void expand(int **hArray, int size, int newSize)
{
	// pass a handle

	int *pNewArray = (int*) malloc(newSize * sizeof(int));
	int i;

	for(i = 0; i< size ;i++)
	{
		pNewArray[i] = (*hArray)[i];
	}

	for(i = size ; i< newSize; i++)
	{
		pNewArray[i] = -42;
	}
	free(*hArray);
	*hArray = pNewArray;
}

/****************************************************************************
 Function: 	 		create

 Description: 	Allocate an int array of size newSize and return the dynamic
 	 	 	 	 	 	 	 memory through the handle

 Parameters:		hArray - the handle to the array
								newSize - the size of the new array
 Returned:	 		none
 ****************************************************************************/
void create(int **hArray, int newSize)
{
	*hArray = (int*) malloc(sizeof( int ) * newSize );
}

/****************************************************************************
 Function: 	 		fill

 Description: 	Fill an array of size with value

 Parameters:		hArray - the handle to the array
								size - the size of the array
								value - the value to put in the array
 Returned:	 		none
 ****************************************************************************/
void fill(int **hArray, int size, int value)
{
	int i;

	for( i = 0; i< size; ++i)
	{
		*hArray[i] = value;
	}
}

/****************************************************************************
 Function: 	 		delete

 Description: 	Deallocate the array

 Parameters:		hArray - the handle to the array

 Returned:	 		none
 ****************************************************************************/
void delete (int **hArray)
{
	free(hArray);
	*hArray = NULL;
}

/****************************************************************************
 Function: 	 		print

 Description: 	print the array, newline separated

 Parameters:		pArray - the array
 	 	 	 	 	 	 	 	size - the size of the array

 Returned:	 		none
 ****************************************************************************/
void print(int *pArray, int size)
{
	int i;

	for( i = 0; i< size; ++i)
	{
		printf("%d\n", pArray[i]);
	}
}

/****************************************************************************
 Function: 	 		main

 Description: 	main driver to exercise the above functions.

 Parameters:		none
 Returned:	 		none
 ****************************************************************************/
int main()
{

	int *pArray;
	const int SIZE = 5;
	int i = 0;
	const int NEW_SIZE = 10;

	printSizes();
	printf("\n");

	create(&pArray, SIZE);

	fill(pArray, SIZE, -2);

	print(&pArray, SIZE);


	printf("\n");

	expand(&pArray, SIZE, NEW_SIZE);

	print(pArray, NEW_SIZE);

	// deallocate pArray
	delete(pArray);

	return EXIT_SUCCESS;
}
