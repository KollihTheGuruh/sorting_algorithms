#include "sort.h"

/**
* get_max - Finds the maximum element in an array of integers.
*
* @array: Pointer to the array.
* @size: Number of elements in the array.
*
* Return: The maximum element in the array.
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

/**
* radix_counting_sort - Performs counting sort based on a specific significant
*                       digit of each element in the array.
*
* @array: Pointer to the array to be sorted.
* @size: Number of elements in the array.
* @sig: The significant digit to sort by (1 for least significant,
* 10 for next significant, etc.).
* @buff: Pointer to the buffer to store the sorted output.
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
* radix_sort - Sorts an array of integers in ascending order using Radix sort.
*
* @array: Pointer to the array to be sorted.
* @size: Number of elements in the array.
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
