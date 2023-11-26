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
 * selection_sort - ascending order sorting
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		minimum = array + a;
		for (b = a + 1; b < size; b++)
			minimum = (array[b] < *minimum) ? (array + b) : minimum;

		if ((array + a) != minimum)
		{
			swap_numbers(array + a, minimum);
			print_array(array, size);
		}
	}
}
