/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:09:47 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/15 14:02:17 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(char c, t_list **stack_a, t_list **stack_b)
{
	t_list	*node;

	if ((c == 'b' && !*stack_a) || (c == 'a' && !*stack_b))
		return ;
	if (c == 'b')
	{
		node = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, node);
	}
	if (c == 'a')
	{
		node = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, node);
	}
	ft_printf("p%c\n", c);
}

void	swap(char c, t_list **stack)
{
	t_list	*node;

	if (!*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	node->next = (*stack)->next;
	(*stack)->next = node;
	ft_printf("s%c\n", c);
}

void	rotate(char c, t_list **stack)
{
	t_list	*node;

	node = *stack;
	if (!node->next)
		return ;
	*stack = (*stack)->next;
	node->next = NULL;
	ft_lstadd_back(stack, node);
	ft_printf("r%c\n", c);
}

void	rrotate(char c, t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*new_tail;

	if (!*stack || !(*stack)->next)
		return ;
	tail = *stack;
	while (tail->next)
	{
		new_tail = tail;
		tail = tail->next;
	}
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
	ft_printf("rr%c\n", c);
}
