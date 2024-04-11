/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:37:33 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/11 13:40:31 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	needs_swap(t_list *stack_a, int num)
{
	t_list	*node;

	node = stack_a;
	while (node && node->next)
	{
		if (node->index == 3 + num && node->next->index == 2 + num)
			return (1);
		node = node->next;
	}
	return (node->index == 3 + num && stack_a->index == 2 + num);
}

static void	three_sort(t_list **stack_a, int num)
{
	if (is_sorted(*stack_a))
		return ;
	if (needs_swap(*stack_a, num))
		swap('a', stack_a);
	else if ((*stack_a)->index == 2 + num)
		rrotate('a', stack_a);
	else if ((*stack_a)->index == 3 + num)
		rotate('a', stack_a);
	three_sort(stack_a, num);
}

void	hardcode(t_list **stack_a, t_list **stack_b, int num)
{
	int	i;

	if (is_sorted(*stack_a))
		return ;
	if (num == 2)
		return (swap('a', stack_a));
	i = 0;
	while (i < num - 3)
	{
		if ((*stack_a)->index <= num - 3)
		{
			push('b', stack_a, stack_b);
			i ++;
		}
		else
			rotate('a', stack_a);
	}
	three_sort(stack_a, num - 3);
	if (num == 5 && (*stack_b)->index == 1)
		swap('b', stack_b);
	return (push('a', stack_b, stack_a), push('a', stack_b, stack_a));
}

void	radix(t_list **stack_a, t_list **stack_b, int dig)
{
	int	i;

	if (is_sorted(*stack_a))
		return ;
	i = ft_lstsize(*stack_a);
	while (--i >= 0)
	{
		if (((*stack_a)->index >> dig) & 1)
			rotate('a', stack_a);
		else
			push('b', stack_a, stack_b);
	}
	while (*stack_b)
		push('a', stack_b, stack_a);
	radix(stack_a, stack_b, ++dig);
}

/*
3 4 5
4 3 5 ---s---> 3 4 5
5 4 3 ---s---> 4 5 3 --rr---> 3 4 5
3 5 4 ---s---> 5 3 4 ---r---> 3 4 5
4 5 3 -------> 4 5 3 --rr---> 3 4 5
5 3 4 -------> 4 5 3 ---r---> 3 4 5
*/
