/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:52:12 by yang              #+#    #+#             */
/*   Updated: 2021/11/09 15:28:36 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (!lst)
		return (0);
	if (lst->next == lst)
		return (1);
	temp = lst->next;
	while (temp != lst)
	{
		count++;
		temp = temp->next;
	}
	if (temp == lst)
		count++;
	return (count);
}
