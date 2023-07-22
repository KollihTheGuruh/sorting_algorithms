#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/* Function: swap_ints
* -------------------
* Swaps the values of two integers by using pointers.
*
* a: Pointer to the first integer.
* b: Pointer to the second integer.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
* max_heapify - Maintains max heap property for a subtree rooted at 'root'
* @array: Pointer to the integer array representing the heap
* @size: The total number of elements in the array
* @base: The base index of the heap (usually 0)
* @root: The root index of the subtree to be heapified
*
* This function maintains the max heap property of a binary heap represented as an
* integer array. It ensures that the value at the 'root' index is greater than or
* equal to its children's values. If it's not, the function recursively swaps the
* root with its largest child and calls itself on the child's index to preserve
* the max heap property throughout the affected subtree.
*
* Note: The array is 0-based indexed.
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

/* heap_sort -Sorts an array using the heap sort algorithm.
* The function takes an integer array and its size as input.
* The original array will be sorted in ascending order.
* Uses the heap data structure to efficiently sort the elements.
* Time complexity: O(n log n)
*
* @param array: Pointer to the integer array to be sorted.
* @param size: The number of elements in the array.
* Description: Implements the sift-down heap sort
* algorithm. Prints the array after each swap.
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
