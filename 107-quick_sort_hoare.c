#include "sort.h"

/**
* swap_ints - Swaps the values of two integers.
*
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
* hoare_partition - Partitions the array using the Hoare partition scheme.
*
* @array: Pointer to the array to be partitioned.
* @size: Number of elements in the array.
* @left: Starting index of the partition.
* @right: Ending index of the partition.
*
* Return: Index of the pivot element after partitioning.
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
* hoare_sort - Sorts an array using Hoare's algorithm.
*
* @array: Pointer to the integer array to be sorted.
* @size: Size of the array.
* @left: Index of the leftmost element in the partition to be sorted.
* @right: Index of the rightmost element in the partition to be sorted.
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
* quick_sort_hoare - Sorts an array of integers in ascending order
*                   using the Quick Sort algorithm (Hoare partition scheme).
* @array: Pointer to the first element of the array to be sorted.
* @size: The number of elements in the array.
*Description: Uses the Hoare partition scheme. Prints
* the array after each swap of two elements.
*/
void quick_sort_hoare(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

hoare_sort(array, size, 0, size - 1);
}
