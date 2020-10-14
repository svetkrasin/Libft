/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:24:53 by svet              #+#    #+#             */
/*   Updated: 2020/10/14 14:31:08 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H
# include "libft.h"
# include <stdarg.h>

int		fmt_proc(t_dlist *heads[3], const char *format, va_list ap);
void	pos_proc(t_dlist **pos_head_p, t_dlist *fmt_head);

#endif
