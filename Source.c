#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int MinValueInArray(int* array , int size, int skipval)
{
	int min = array[0];

	if (skipval >= array[0])
		min = array[1];
	
	if (skipval >= array[1])
		min = array[2];

	for(int i = 1; i < size ; i++)
	{	
		if (skipval != NULL)
		{
			if (array[i] < min && array[i] > skipval)
				min = array[i];
		}
		else
		{
			if (array[i] < min )
				min = array[i];
		}
	}

	return min;
}


 int main()
{
	int* array;
	int size, i;
	printf("print the quantity of elements in the array: ");

	scanf_s("%d", &size);

	array = (int*)malloc(size * sizeof(int));

	printf("enter the elements:");

	for (i = 0; i < size; i++)
	{
		scanf_s("%d", array + i);
	}
	printf("Your array is:  ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	if (size > 2)
	{
	    int min = MinValueInArray(array, size, NULL);
		min = MinValueInArray(array, size, min);
		min = MinValueInArray(array, size, min);

		printf(" The result is : %d \n", min);
	}
	else
		printf("The result is : -1 \n ");
	free(array);
	
	return 0;
}
 