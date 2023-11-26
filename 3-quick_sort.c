#include "sort.h"

void organize_with_lomuto(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);
void swap_numbers(int *x, int *y);
int lomuto_scheme(int *array, size_t size, int left, int right);

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
 * lomuto_scheme - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_scheme(int *array, size_t size, int left, int right)
{
	int *pivot, up, down;

	pivot = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
			swap_numbers(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_numbers(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}

/**
 * organize_with_lomuto - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Return - none
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int value;

	if (right - left > 0)
	{
		value = lomuto_scheme(array, size, left, right);
		organize_with_lomuto(array, size, left, part - 1);
		organize_with_lomuto(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Try sorting using quick sort algorithm
 * @array: the specified array
 * @size: its size
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	organize_with_lomuto(array, size, 0, size - 1);
}
