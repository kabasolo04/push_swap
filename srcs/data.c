/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:44:59 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/16 12:19:52 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	src_low_num(t_list *stack_a)
{
	int	n;

	n = 2147483647;
	while (stack_a)
	{
		if ((int)stack_a->content <= n && stack_a->index == 0)
			n = (int)stack_a->content;
		stack_a = stack_a->next;
	}
	return (n);
}

static void	index_to_zero(t_list *stack_a)
{
	if (stack_a)
	{
		stack_a->index = 0;
		index_to_zero(stack_a->next);
	}
}

static void	get_index(t_list *stack_a)
{
	int		index;
	int		n;
	t_list	*node;

	index_to_zero(stack_a);
	index = 1;
	while (index <= ft_lstsize(stack_a))
	{
		node = stack_a;
		n = src_low_num(stack_a);
		while (node && (int)node->content != n)
			node = node->next;
		node->index = index;
		index ++;
	}
}

static void	get_numbers(char **mtrx, t_list	**stack_a)
{
	t_list	*node;

	while (*mtrx)
	{
		node = ft_lstnew((void *)ft_atol(mtrx[0]));
		if (!node)
			return ;
		ft_lstadd_back(stack_a, node);
		mtrx ++;
	}
}

int	get_stack(t_list **stack_a, int argc, char **argv)
{
	char	**mtrx;

	if (argc < 2)
		return (0);
	argv ++;
	if (argc == 2)
		mtrx = ft_split(argv[0], ' ');
	else
		mtrx = mtrx_cpy(argv);
	if (!mtrx)
		return (1);
	if (all_num(mtrx))
	{
		get_numbers(mtrx, stack_a);
		if (!num_rep(*stack_a) && all_int(*stack_a))
			return (get_index(*stack_a), mtrx_free(mtrx), 0);
	}
	return (mtrx_free(mtrx), 1);
}
