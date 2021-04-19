/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtxnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:42:23 by svet              #+#    #+#             */
/*   Updated: 2021/04/15 15:21:38 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include "ft_memory.h"
#include <sys/_types/_null.h>

t_matrix	*ft_mtxnew(size_t rows, size_t columns)
{
	t_matrix	*matrix;

	if (columns < 1 || rows < 1 ||
	(matrix = (t_matrix *)ft_memalloc(sizeof(t_matrix))) == NULL ||
	(matrix->content = (long double *)ft_memalloc(columns * rows *
												sizeof(long double))) == NULL)
		return (NULL);
	matrix->rows = rows;
	matrix->columns = columns;
	return (matrix);
}
