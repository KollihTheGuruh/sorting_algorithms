
#include <stdio.h>

/**
 * swap - Swaps the values of two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 * Bubble Sort algorithm.
 *
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 */

void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;
	size_t k; /* Move 'k' outside the for loop */

	printf("%d", array[0]);
	for (i = 1; i < size; i++)
	{
	printf(", %d", array[i]);
	}
	printf("\n");

	for (i = 0; i < size - 1; i++)
	{
	swapped = 0;
	for (j = 0; j < size - i - 1; j++)
	{
		if (array[j] > array[j + 1])
		{
		swap(&array[j], &array[j + 1]);
	swapped = 1;
	}
	}
	if (!swapped)
		break;

	printf("%d", array[0]);
	for (k = 1; k < size; k++)
	{
		printf(", %d", array[k]);
	}
	printf("\n");
	}
}
