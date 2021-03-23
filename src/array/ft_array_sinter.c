/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_sinter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:09:46 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/23 12:30:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/array.h"
#include "libft/internal/array_int.h"
#include "libft/cstring.h"

/*
** NOTE: To be clear, the way this code is organized is ugly and I know it.
** I did not find any other suitable way to code that function without
** infringing 42's norm. That's stupid code, but at least it works.
** Rework of this function without the norm restrictions is planned.
*/

t_array	get_new_array(t_array a1)
{
	t_array_int	*new;

	new = (t_array_int *)ft_array_new(((t_array_int *)a1)->size);
	if (new == NULL)
	{
		return (NULL);
	}
	return (new);
}

/*
** Add the element to the new array one time and increment both index pointers.
** Skip duplicates as we don't want to trigger this procedure another time
** for them.
*/

static void	handle_ret_zero(t_array_int **arrs, int *iter,
		int (*cmp)(void *el1, void *el2))
{
	void	*tmp;

	arrs[2]->array[arrs[2]->length] = arrs[0]->array[iter[0]++];
	tmp = arrs[2]->array[arrs[2]->length++];
	++iter[1];
	while (iter[0] < arrs[0]->length && cmp(arrs[0]->array[iter[0]], tmp) == 0)
		iter[0]++;
	while (iter[1] < arrs[1]->length && cmp(arrs[1]->array[iter[1]], tmp) == 0)
		iter[1]++;
}

t_array	ft_array_sinter(t_array a1, t_array a2,
		int (*cmp)(void *el1, void *el2))
{
	int				iter[2];
	t_array_int		*arrs[3];
	int				ret;

	ft_memset(iter, 0, sizeof(iter));
	arrs[0] = (t_array_int *)a1;
	arrs[1] = (t_array_int *)a2;
	arrs[2] = get_new_array(a1);
	if (arrs[2] == NULL)
		return (NULL);
	while (iter[0] < arrs[0]->length)
	{
		ret = cmp(arrs[0]->array[iter[0]], arrs[1]->array[iter[1]]);
		if (ret > 0)
			++iter[1];
		else if (ret == 0)
			handle_ret_zero(arrs, iter, cmp);
		else
			++iter[0];
	}
	return (arrs[2]);
}