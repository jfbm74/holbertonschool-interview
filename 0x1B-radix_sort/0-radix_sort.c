#include "sort.h"

/**
* max_num - find the maximun value number in a array
* @arr: array to sort
* @size: size of array to sort
* Return: maximun number of the array
*/
int max_num(int *arr, size_t size)
{
	int max_n = 0;
	size_t i = 0;

	for (max_n = arr[0], i = 1; i < size; i++)
		if (arr[i] > max_n)
			max_n = arr[i];

	return (max_n);
}

/**
* radix_order - sort the elements in the basis of significant places
* @arr: array to sort
* @size: size of array to sort
* @exp: current digital exponent
* Return: the array ordered by a specific digit, NULL otherwise
*/
int *radix_order(int *arr, size_t size, int exp)
{
	int *sort_d = NULL, dig[10] = {0}, j = 0;
	size_t i = 0;

	sort_d = malloc(sizeof(int) * size);
	if (!sort_d)
		return (NULL);

	for (i = 0; i < size; i++)
		dig[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		dig[i] += dig[i - 1];

	for (j = size - 1; j >= 0; j--)
	{
		sort_d[dig[(arr[j] / exp) % 10] - 1] = arr[j];
		dig[(arr[j] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = sort_d[i];

	free(sort_d);
	return (arr);
}

/**
 * radix_sort - sorts an array of integers in ascending order using
 * the LSD radix sort algorithm
 * @array: array to sort
 * @size: size of array to sort
 **/

void radix_sort(int *array, size_t size)
{
	int max_n = 0, exp = 0;

	if (array == NULL || size < 2)
		return;

	max_n = max_num(array, size);
	for (exp = 1; (max_n / exp) > 0; exp *= 10)
	{
		if (!radix_order(array, size, exp))
			return;
		print_array(array, size);
	}
}
