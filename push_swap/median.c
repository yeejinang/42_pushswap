/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:08:35 by yang              #+#    #+#             */
/*   Updated: 2021/11/16 13:02:32 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    copyData(t_stack *stack, int array[], int size)
{
	t_node	*temp;
	int		i;

	//printf("copy data %p\t %p\n", *stack, stack);
	i = -1;
	temp = stack->tail;
	temp = temp->next;
	//printf("%d\n", tail->content);
	while (size)
	{
		array[++i] = temp->content;
		//printf("array: %d\n", array[i]);
		temp = temp->next;
		size--;
	}
}

static void merge(int arr[], int l, int m, int r)
{
    int i;
	int	j;
	int k;
    int	L[m - l + 1];
	int	R[r - m];
  
   i = -1;
    while (++i < (m - l + 1))
        L[i] = arr[l + i];
	j = -1;
    while (++j < (r - m))
        R[j] = arr[m + 1 + j];
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < (m - l + 1) && j < (r - m)) 
	{
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < (m - l + 1))
        arr[k++] = L[i++];
    while (j < (r - m))
        arr[k++] = R[j++];
}
  
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
static void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
    }
}

int     getMedian(t_stack *stack, int size)
{
    int     median;
    int 	array[size];
	int		i;

	i = -1;
    //printf("%p\t %d\n", *head_Ref, size);
	copyData(stack, array, size);
    mergeSort(array, 0, size - 1);
	/*while (++i < size)
		printf("sorted: %d\n", array[i]);*/
    if (!size % 2)
        median = (array[size / 2 - 1] + array[size / 2]) / 2;
    else
        median = array[size / 2];
    return (median);
}