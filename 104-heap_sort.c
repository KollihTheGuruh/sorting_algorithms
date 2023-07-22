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
 * max_heapify - Rearranges elements in the array to maintain
 * the max heap property.
 *
 * @array: Pointer to the array representing the binary heap.
 * @size: Number of elements in the array.
 * @base: Base index of the subarray to consider for max heapify.
 * @root: Index of the root node of the subarray.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;

left = 2 * root + 1;
right = 2 * root + 2;
large = root;

if (left < base && array[left] > array[large])
large = left;
if (right < base && array[right] > array[large])
large = right;

if (large != root)
{
swap_ints(array + root, array + large);
print_array(array, size);
max_heapify(array, size, base, large);
}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
int i;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
max_heapify(array, size, size, i);

for (i = size - 1; i > 0; i--)
{
swap_ints(array, array + i);
print_array(array, size);
max_heapify(array, size, i, 0);
}
}
