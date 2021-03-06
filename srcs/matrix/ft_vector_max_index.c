/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_max_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:53:53 by svet              #+#    #+#             */
/*   Updated: 2021/04/25 12:33:02 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

size_t	ft_vector_max_index(const t_vector *v)
{
	const size_t		stride = v->stride;
	const long double	*content;
	long double			max;
	long double			imax;
	size_t				i;

	content = v->content;
	max = content[0];
	imax = 0;
	i = 1;
	while (i < v->size)
	{
		if (max < content[i * stride])
		{
			max = content[i * stride];
			imax = i;
		}
		++i;
	}
	return (imax);
}
