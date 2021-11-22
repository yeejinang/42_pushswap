/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:08:35 by yang              #+#    #+#             */
/*   Updated: 2021/11/22 13:49:07 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_data(t_stack *stack, int array[], int size)
{
	t_node	*temp;
	int		i;

	i = -1;
	temp = stack->tail;
	temp = temp->next;
	while (size)
	{
		array[++i] = temp->content;
		temp = temp->next;
		size--;
	}
}

/*static void	merge(int arr[], int l, int m, int r)
{
	int	i;
	int	j;
	int	k;
	int	left[m - l + 1];
	int	right[r - m];

	i = -1;
	while (++i < (m - l + 1))
        left[i] = arr[l + i];
	j = -1;
    while (++j < (r - m))
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < (m - l + 1) && j < (r - m)) 
	{
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < (m - l + 1))
        arr[k++] = left[i++];
    while (j < (r - m))
        arr[k++] = right[j++];
}

static void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
    }
}*/

static void	med_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	med_partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			med_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	med_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	med_quicksort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = med_partition(arr, low, high);
		med_quicksort(arr, low, pi - 1);
		med_quicksort(arr, pi + 1, high);
	}
}

int	get_median(t_stack *stack, int size)
{
	int	median;
	int	array[500];
	int	i;

	i = -1;
	copy_data(stack, array, size);
	med_quicksort(array, 0, size - 1);
	if (!size % 2)
		median = (array[size / 2 - 1] + array[size / 2]) / 2;
	else
		median = array[size / 2];
	return (median);
}
