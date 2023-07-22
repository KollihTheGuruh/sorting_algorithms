#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
* swap_ints - Swaps the values of two integers using pointers.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}


/**
* hoare_partition - Partitions the given array using the Hoare algorithm.
*
* This function takes an array and partitions it using the Hoare algorithm.
* It selects the pivot element and rearranges the elements such that all
* elements to the left of the pivot are less than or equal to the pivot,
* and all elements to the right are greater than the pivot.
*
* @array: Pointer to the array to be partitioned.
* @size: Size of the array.
* @left: Index of the leftmost element of the partition.
* @right: Index of the rightmost element of the partition.
*
* Return: The index of the pivot element after partitioning.
* Prints the array after each swap of two elements.
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
int pivot, above, below;

pivot = array[right];
for (above = left - 1, below = right + 1; above < below;)
{
do {
above++;
} while (array[above] < pivot);
do {
below--;
} while (array[below] > pivot);

if (above < below)
{
swap_ints(array + above, array + below);
print_array(array, size);
}
}

return (above);
}

/**
* hoare_sort - Sorts an array of integers using the Quick Sort algorithm
*              with the Hoare partition scheme.
*
* @array: Pointer to the array to be sorted.
* @size: Number of elements in the array.
* @left: Starting index of the partition.
* @right: Ending index of the partition.
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = hoare_partition(array, size, left, right);
hoare_sort(array, size, left, part - 1);
hoare_sort(array, size, part, right);
}
}

/**
* quick_sort_hoare - Sorts an array of integers in ascending order using the
*                    Quick Sort algorithm with the Hoare partition scheme.
*
* @array: Pointer to the array to be sorted.
* @size: Number of elements in the array.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}
