#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/*
* swap_ints - Swaps the values of two integers using pointers.
* @a: Pointer to the first integer.
* @b: Pointer to the second integer.
* Description: This function takes two integer
* pointers as input and swaps the values
* of the integers they point to.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/*
* hoare_partition - Performs Hoare partitioning on an array segment.
* @array: Pointer to the array to be partitioned.
* @size: Size of the array.
* @left: Index of the leftmost element of the segment to partition.
* @right: Index of the rightmost element of the segment to partition.
* Description: The Hoare partition scheme is a
* popular algorithm used in various
* sorting and searching algorithms. It selects a pivot element and
* rearranges the array in such a way that all elements less than or
* equal to the pivot come before it and all elements greater than
* the pivot come after it. This function returns the index of the pivot
* element after the partitioning process.
* Return: The index of the pivot element after partitioning.
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
