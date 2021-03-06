/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 15:47:15 by svet              #+#    #+#             */
/*   Updated: 2021/04/15 15:25:43 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H
# include <_types/_intmax_t.h>
# include <_types/_uintmax_t.h>
# include <sys/types.h>

unsigned int	ft_num_of_digs(intmax_t n, int base);
unsigned int	ft_unum_of_digs(uintmax_t n, int base);

typedef struct	s_parts
{
# if defined(__BIG_ENDIAN__)

	u_int32_t msw;
	u_int32_t lsw;
# else

	u_int32_t lsw;
	u_int32_t msw;
# endif

}				t_parts;

typedef union	u_ieee_double_shape_type
{
	long double	value;
	t_parts		parts;
}				t_ieee_double_shape_type;

int				ft_max(int a, int b);
long double		ft_ldmax(long double a, long double b);
int				ft_min(int a, int b);
long double		ft_ldmin(long double a, long double b);
int				ft_isinf(long double d);
int				ft_isnan(long double x);
long long int	ft_llabs(long long int val);
long double		ft_lpow(long double base, long int exp);
long double		ft_ldabs(long double val);
long double		ft_ldround(long double base, int prec);

#endif
