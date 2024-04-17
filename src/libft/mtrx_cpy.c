/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtrx_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:42:38 by kabasolo          #+#    #+#             */
/*   Updated: 2024/04/11 13:36:24 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**mtrx_cpy(char **mtrx)
{
	int		i;
	int		t;
	char	**cpy;

	i = mtrx_len(mtrx);
	cpy = (char **)malloc((i + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	cpy[i] = NULL;
	i = 0;
	while (mtrx[i])
	{
		t = 0;
		cpy[i] = (char *)ft_calloc((ft_strlen(mtrx[i]) + 1), sizeof(char ));
		if (!cpy[i])
			return (mtrx_free(cpy), NULL);
		while (mtrx[i][t])
		{
			cpy[i][t] = mtrx[i][t];
			t ++;
		}
		i ++;
	}
	return (cpy);
}
