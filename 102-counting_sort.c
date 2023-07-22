#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* counting_sort - Sorts an array of integers in ascending order using
*                the Counting sort algorithm.
*
* @array: Pointer to the array of integers to be sorted.
* @size: Size of the array.
*/
void counting_sort(int *array, size_t size)
{
int *count, *output, max, i, j;

if (array == NULL || size <= 1)
return;

max = array[0];
for (i = 1; i < (int)size; i++)
{
if (array[i] > max)
max = array[i];
}
count = malloc((max + 1) * sizeof(int));
if (count == NULL)
return;

for (i = 0; i <= max; i++)
count[i] = 0;

for (i = 0; i < (int)size; i++)
count[array[i]]++;

for (i = 1; i <= max; i++)
count[i] += count[i - 1];
output = malloc(size * sizeof(int));
if (output == NULL)
{
free(count);
return;
}
for (i = size - 1; i >= 0; i--)
{
j = count[array[i]] - 1;
output[j] = array[i];
count[array[i]]--;
}
for (i = 0; i < (int)size; i++)
array[i] = output[i];
free(count);
free(output);
}
