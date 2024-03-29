#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - function that swaps two integers in an array
 * @a: 1st integer
 * @b: 2nd integer
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - function that orders a subset of an array of integers
 *                   according to the hoare partition scheme
 * @array: the array of integers
 * @size: the size of the array
 * @left: the starting index of the subset to order
 * @right: the ending index of the subset to order
 * Return: the final partition index
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - function that implements the quicksort algorithm
 *              through recursion
 * @array: array of integers to sort
 * @size: the size of the array
 * @left: the starting index of the array partition to order
 * @right: the ending index of the array partition to order
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers in ascending
 *                    order using the quicksort algorithm
 * @array: array of integers
 * @size: the size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
