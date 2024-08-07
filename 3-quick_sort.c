#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* swap - Swaps two elements in an array
* @array: The array in which to swap elements
* @i: Index of the first element
* @j: Index of the second element
* @size: Size of the array
*/
void swap(int *array, size_t i, size_t j, size_t size)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
* @array: The array to be partitioned
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: Size of the array
* Return: The index of the pivot after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
* quick_sort_rec - Recursive Quick sort function
* @array: The array to be sorted
* @low: The starting index of the partition
* @high: The ending index of the partition
* @size: Size of the array
*/
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		quick_sort_rec(array, low, pi - 1, size);
		quick_sort_rec(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: The array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
