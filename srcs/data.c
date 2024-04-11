/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:44:59 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/11 13:37:24 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	src_low_num(t_list *stack_a, int n)
{
	while (stack_a)
	{
		if ((int)stack_a->content <= n && stack_a->index == 0)
			n = (int)stack_a->content;
		stack_a = stack_a->next;
	}
	return (n);
}

static void	get_index(t_list **stack_a)
{
	int		index;
	int		n;
	t_list	*node;

	node = *stack_a;
	while (node)
	{
		node->index = 0;
		node = node->next;
	}
	index = 1;
	while (index <= ft_lstsize(*stack_a))
	{
		node = *stack_a;
		n = src_low_num(*stack_a, 2147483647);
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
	int		i;

	if (argc < 2)
		return (1);
	argv ++;
	if (argc == 2)
		mtrx = ft_split(argv[0], ' ');
	else
		mtrx = mtrx_cpy(argv);
	i = 0;
	if (!all_num(mtrx))
		return (ft_printf("SOLO NUMEROS MAMAWEBO\n"), 1);
	get_numbers(mtrx, stack_a);
	if (num_rep(*stack_a))
		return (ft_printf("NO REPITAS NUMEROS ETUPIDO\n"), 1);
	if (!all_int(*stack_a))
		return (ft_printf("NO TE PASES DE LOS INT MAX Y MIN\n"), 1);
	get_index(stack_a);
	mtrx_free(mtrx);
	return (0);
}
