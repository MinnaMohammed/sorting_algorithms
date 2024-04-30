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
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 *@array: input array
 *@size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_values((array + j), (array + j + 1));
				print_array(array, size);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}
