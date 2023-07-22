#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);


/**
* get_max -Returns the maximum value in the given array.
*
* @array: A pointer to the integer array.
* @size: The number of elements in the array.
*
* Returns:
* The maximum value in the array. If the array is empty (size <= 0), returns 0.
*/
int get_max(int *array, int size)
{
int max, i;

for (max = array[0], i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

return (max);
}

/*
* radix_counting_sort- Performs radix counting sort on
* the input array in ascending order.
* Uses the base-10 representation of integers for sorting.
*
* @array: Pointer to the integer array to be sorted.
* @size:  Number of elements in the array.
* @sig:   Significant digit to consider during sorting
* (1 for least significant digit, 10 for next significant, and so on).
* @buff:  Pointer to an auxiliary buffer array with the same size as the input array.
*
* Returns: void
*/
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i;

for (i = 0; i < size; i++)
count[(array[i] / sig) % 10] += 1;

for (i = 0; i < 10; i++)
count[i] += count[i - 1];

for (i = size - 1; (int)i >= 0; i--)
{
buff[count[(array[i] / sig) % 10] - 1] = array[i];
count[(array[i] / sig) % 10] -= 1;
}

for (i = 0; i < size; i++)
array[i] = buff[i];
}

/**
* radix_sort -Sorts an array of integers using the Radix Sort algorithm.
*
* @param array Pointer to the first element of the array to be sorted.
* @param size  Number of elements in the array.
* Description: Implements the LSD radix sort algorithm. Prints
* the array after each significant digit increase.
*/
void radix_sort(int *array, size_t size)
{
int max, sig, *buff;

if (array == NULL || size < 2)
return;

buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

max = get_max(array, size);
for (sig = 1; max / sig > 0; sig *= 10)
{
radix_counting_sort(array, size, sig, buff);
print_array(array, size);
}

free(buff);
}
