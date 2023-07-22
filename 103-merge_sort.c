#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
* merge_subarr - Merge two subarrays into one sorted array.
* @subarr: Pointer to the first element of the subarray to be merged.
* @buff: Pointer to the temporary buffer to store the merged elements.
* @front: Index of the front element of the first subarray.
* @mid: Index of the element that separates the two subarrays.
* @back: Index of the last element of the second subarray.
*
* This function merges two sorted subarrays into one sorted array. It uses a
* temporary buffer (buff) to store the merged elements and then copies them
* back to the original subarray (subarr) in sorted order.
*
* The subarrays to be merged are defined by the range [front, mid] and
* [mid + 1, back]. The elements in these subarrays must be in ascending order
* for the merge to work correctly.
*
* The function modifies the contents of the subarray pointed to by subarr.
*
* Return: None (void).
*/
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
size_t back)
{
size_t i, j, k = 0;

printf("Merging...\n[left]: ");
print_array(subarr + front, mid - front);

printf("[right]: ");
print_array(subarr + mid, back - mid);

for (i = front, j = mid; i < mid && j < back; k++)
buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
for (; i < mid; i++)
buff[k++] = subarr[i];
for (; j < back; j++)
buff[k++] = subarr[j];
for (i = front, k = 0; i < back; i++)
subarr[i] = buff[k++];

printf("[Done]: ");
print_array(subarr + front, back - front);
}

/*
* merge_sort_recursive - Recursively sorts a subarray using merge sort algorithm.
* @subarr: Pointer to the beginning of the subarray.
* @buff: Temporary buffer for merging.
* @front: Index of the first element in the subarray.
* @back: Index of the last element in the subarray.
*/
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
size_t mid;

if (back - front > 1)
{
mid = front + (back - front) / 2;
merge_sort_recursive(subarr, buff, front, mid);
merge_sort_recursive(subarr, buff, mid, back);
merge_subarr(subarr, buff, front, mid, back);
}
}

/**
* merge_sort - Sorts an array of integers in ascending order using the
*              Merge Sort algorithm.
*
* @array: Pointer to the array to be sorted.
* @size: Size of the array.
* Description: Implements the top-down merge sort algorithm.
*/
void merge_sort(int *array, size_t size)
{
int *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

merge_sort_recursive(array, buff, 0, size);

free(buff);
}
