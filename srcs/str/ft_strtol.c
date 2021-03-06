/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 13:54:32 by svet              #+#    #+#             */
/*   Updated: 2020/09/01 20:20:48 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_string.h"
#include <limits.h>
#include <sys/_types/_null.h>

static inline int			ft_ishex(const char *s, int base)
{
	return ((base == 0 || base == 16) &&
			*s == '0' && (s[1] == 'x' || s[1] == 'X') &&
			((s[2] >= '0' && s[2] <= '9') ||
			(s[2] >= 'A' && s[2] <= 'F') ||
			(s[2] >= 'a' && s[2] <= 'f')));
}

static inline char			ft_parsechr(char c)
{
	if (c >= '0' && c <= '9')
		c -= '0';
	else if (c >= 'A' && c <= 'Z')
		c -= 'A' - 10;
	else if (c >= 'a' && c <= 'z')
		c -= 'a' - 10;
	return (c);
}

static inline size_t		ft_countdigs(const char *str, int base)
{
	size_t n;

	n = 0;
	while (ft_parsechr(*str) < base)
	{
		++str;
		++n;
	}
	return (n);
}

static inline unsigned long	ft_parsestr(
	const char *s,
	const long sign,
	const int base,
	int *const pany
)
{
	register unsigned long	acc;
	register unsigned long	cutoff;
	register int			cutlim;
	register int			any;
	register char			c;

	any = 0;
	acc = sign == -1L ? 1UL - ((unsigned long)LONG_MIN +
								(unsigned long)LONG_MAX) + LONG_MAX : LONG_MAX;
	cutoff = acc / (const unsigned long)base;
	cutlim = (int)(acc % (const unsigned long)base);
	acc = 0;
	while (ft_isalnum((c = *s++)) != 0)
		if ((c = ft_parsechr(c)) >= base)
			break ;
		else if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
			any = -1;
		else if ((any = 1))
			acc = acc * (const unsigned long)base + (unsigned long)c;
	if (any < 0)
		acc = (unsigned long)(sign == -1L ? LONG_MIN : LONG_MAX);
	else
		acc *= (const unsigned long)sign;
	*pany = any;
	return (acc);
}

long						ft_strtol(const char *nptr, char **endptr, int base)
{
	const char			*s;
	long				sign;
	int					any;
	unsigned long		acc;

	s = nptr;
	while (ft_isspace((unsigned char)*s) != 0)
		s++;
	sign = *s == '-' || *s == '+' ? ',' - *s++ : 1L;
	if (ft_ishex(s, base))
	{
		s += 2;
		base = 16;
	}
	if (base == 0)
		base = *s++ == '0' ? 8 : 10;
	if (base < 2 || base > 36)
		return (0);
	acc = ft_parsestr(s, sign, base, &any);
	if (endptr != NULL)
		*endptr = (char *)(any ? s + ft_countdigs(s, base) : nptr);
	return ((long)acc);
}
