/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:41:45 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/17 13:36:39 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dummy(void *node)
{
	if (node)
		return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (get_stack(&stack_a, argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (ft_lstsize(stack_a) > 5)
		radix(&stack_a, &stack_b, 0);
	else
		hardcode(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_lstclear(&stack_a, dummy);
	//system("leaks push_swap");
	return (0);
}
