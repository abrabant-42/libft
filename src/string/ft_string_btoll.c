/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_btoll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 00:27:13 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/27 00:55:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"
#include "libft/cstring.h"
#include "libft/internal/string_int.h"

long long	ft_string_btoll(t_string_int *str, unsigned char base)
{
	static const char *const	set = "0123456789abcdef";
	long long					nb;	
	char						*ch;
	char						sign;
	size_t						i;

	i = 0;
	nb = 0;
	sign = 1;
	while (i < str->length && ft_isspace(str->chrs[i]))
		++i;
	if (str->chrs[i] == '+' || str->chrs[i] == '-')
		if (str->chrs[i++] == '-')
			sign = -1;
	ch = ft_strchr(set, ft_tolower(str->chrs[i]));
	while (i++ < str->length && ch != NULL)
	{
		nb = nb * base + (ch - set);
		ch = ft_strchr(set, ft_tolower(str->chrs[i]));
	}
	return (nb * sign);
}
