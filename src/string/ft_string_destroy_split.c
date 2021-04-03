/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_destroy_split.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:20:37 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/03 11:21:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/string.h"

void	ft_string_destroy_split(void *split)
{
	ft_array_destroy((t_array) split, (void (*)(void *))ft_string_destroy);
}
