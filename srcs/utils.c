/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:58:28 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/11 13:40:43 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

int	all_num(char **mtrx)
{
	int	i;

	while (mtrx[0])
	{
		i = (mtrx[0][0] == '+' || mtrx[0][0] == '-');
		if (!mtrx[0][i])
			return (0);
		while (mtrx[0][i])
		{
			if (!ft_isdigit(mtrx[0][i]))
				return (0);
			i ++;
		}
		mtrx ++;
	}
	return (1);
}

int	num_rep(t_list *stack)
{
	t_list	*node;

	while (stack)
	{
		node = stack->next;
		while (node)
		{
			if (stack->content == node->content)
				return (1);
			node = node->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	all_int(t_list *stack)
{
	long	value;

	while (stack)
	{
		value = (long)(stack->content);
		if (value < -2147483648 || value > 2147483647)
			return (0);
		stack = stack->next;
	}
	return (1);
}
