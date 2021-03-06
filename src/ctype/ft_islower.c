/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:33:15 by abrabant          #+#    #+#             */
/*   Updated: 2020/09/30 19:36:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** libft implementation of islower(3)
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
