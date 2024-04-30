#include "sort.h"

/**
 * swap_values - swaps 2 numbers
 *
 *@num1: first number
 *@num2: second number
*/
void swap_values(int *num2, int *num1)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * partition - divides the given array into 2 partitions
 *
 *@array: input array
 *@low: first element
 *@high: last element
 *@size: size of the given array
 *
 * Return: the pivot element
*/
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap_values(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[j])
	{
		swap_values(array + i, array + high);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick - recursive function that splits the array recursively
 *
 *@array: input array
 *@start: first element
 *@end: last element
 *@size: size of the input list
*/
void quick(int *array, size_t start, size_t end, size_t size)
{
	int i;

	if (start < end)
	{
		i = partition(array, start, end, size);
		if (i > 0)
			quick(array, start, i - 1, size);
		quick(array, i + 1, end, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 *@array: input list
 *@size: size of the input list
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick(array, 0, size - 1, size);
}



