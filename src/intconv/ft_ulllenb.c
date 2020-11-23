/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllenb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:20:40 by abrabant          #+#    #+#             */
/*   Updated: 2020/11/23 19:29:53 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/types.h"

size_t	ft_ulllenb(unsigned long long n, t_byte base)
{
	size_t	 c;

	c = 1;
	while (n /= base)
		++c;
	return (c);
}
