#include "sort.h"

/**
 * swap_numbers - interchange the position of
 * two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_numbers(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool boolean = false;

	if (array == NULL || size < 2)
		return;

	while (boolean == false)
	{
		boolean = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_numbers(array + i, array + i + 1);
				print_array(array, size);
				boolean = false;
			}
		}
		length--;
	}
}
