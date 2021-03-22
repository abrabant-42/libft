/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_concat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:20:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/22 19:35:12 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/cstring.h"
#include "libft/array.h"
#include "libft/internal/array_int.h"

t_array	ft_array_concat(t_array a1, t_array a2)
{
	t_array_int	*new;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->size
			+ ((t_array_int *)a2)->size);
	if (new == NULL)
	{
		return (NULL);
	}
	new->length = ((t_array_int *)a1)->length + ((t_array_int *)a2)->length;
	ft_memcpy(new->array, ((t_array_int *)a1)->array,
			sizeof(*new->array) * ((t_array_int *)a1)->length);
	ft_memcpy(new->array +  ((t_array_int *)a1)->length,
			((t_array_int *)a2)->array,
			sizeof(*new->array) * ((t_array_int *)a2)->length);
	return (new);
}
