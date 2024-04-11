/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:00:52 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/11 13:28:41 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

//Data:
int		get_stack(t_list **stack_a, int argc, char **argv);
//Sort:
void	radix(t_list **stack_a, t_list **stack_b, int dig);
void	hardcode(t_list **stack_a, t_list **stack_b, int num);
//Moves:
void	push(char c, t_list **stack_a, t_list **stack_b);
void	swap(char c, t_list **stack);
void	rotate(char c, t_list **stack_a);
void	rrotate(char c, t_list **stack_a);
//Utils:
int		is_sorted(t_list *list);
int		all_num(char **mtrx);
int		num_rep(t_list *stack);
int		all_int(t_list *stack_a);

#endif //PUSH_SWAP_H