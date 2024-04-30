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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 *@array: input array
 *@size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int flag = 0, min = 0, minIndex = 0;

	if (!array || size < 2)
	{
		return;
	}

	j = 1;
	while (j < size)
	{
		min = *(array + j - 1);
		flag = 0;
		for  (i = j; i <= size - 1; i++)
		{
			if (min > *(array + i))
			{
				min = *(array + i);
				minIndex = i;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			swap_values((array + j - 1), (array + minIndex));
			print_array(array, size);
		}
		j++;
	}
}
