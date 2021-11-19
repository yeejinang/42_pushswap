/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:37:56 by yang              #+#    #+#             */
/*   Updated: 2021/11/09 18:09:56 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;
	//t_list	*temp_new;
	
	//printf("size of lst: %d\n", ft_lstsize(*lst));
	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	/*else if (ft_lstsize(*lst) == 1)
	{
		temp = *lst;
		new->prev = *lst;
		new->next = *lst;
		temp->prev = new;
		temp->next = new;
	}*/
	else
	{
		temp = *lst;
		//new->prev = *lst;
		//temp = temp->next;
		new->next = temp->next;
		//temp->next->prev = new;
		temp->next = new;
		*lst = temp;
	}
}
