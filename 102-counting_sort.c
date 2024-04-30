#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 *@array: input array
 *@size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int max, i;
	size_t j;
	int *countingArr, *sortingArr;

	if (!array || size < 2)
		return;

	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	sortingArr = malloc(sizeof(int) * size);
	countingArr = malloc(sizeof(int) * (max + 1));

	if (!countingArr && !sortingArr)
	{
		free(sortingArr);
		free(countingArr);
		return;
	}
	for (i = 0; i <= max; i++)
		countingArr[i] = 0;
	for (j = 0; j < size; j++)
		countingArr[array[j]]++;
	for (i = 1; i <= max; i++)
		countingArr[i] = countingArr[i] + countingArr[i - 1];
	print_array(countingArr, max + 1);
	for (i = (int)(size - 1); i >= 0; i--)
	{
		sortingArr[countingArr[array[i]] - 1] = array[i];
		countingArr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sortingArr[j];
	free(sortingArr);
	free(countingArr);
}
