/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:19:56 by yang              #+#    #+#             */
/*   Updated: 2021/11/24 18:59:03 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_elem(t_info *st_info)
{
	while (st_info->st_a->count)
		pop(st_info->st_a);
	free(st_info->st_a);
	free(st_info->st_b);
	free(st_info);
}