/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 19:09:50 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 20:19:58 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

t_perm 		init_perm(char *init_str)
{
	t_perm	permutation;

	permutation.str = gnl_concat(init_str, "", 0, 0);
	permutation.count = 1;
	return (permutation);
}

int			contains(t_perm *list, char *target, int list_len)
{
	int		i;

	i = 0;
	while (i < list_len)
	{
		if (ft_strequ(list[i].str, target))
			return (i);
		i++;
	}
	return (-1);
}

void		cleanup(t_perm *list, int list_len)
{
	int		i;

	i = 0;
	while (i < list_len)
	{
		free(list[i].str);
		//free(list[i]);
		i++;
	}
	free(list);
}

char		*to_string(t_perm elem)
{
	char	*ret;

	ret = gnl_concat("key:\t\"", elem.str, 0, 0);
	ret = gnl_concat(ret, "\"\tcount:\t", 1, 0);
	ret = gnl_concat(ret, ft_itoa(elem.count), 1, 1);

	return (ret);
}

void		save_permutations(t_perm *arr, unsigned int arr_len, int fd)
{
	unsigned int	i;
	char			*curr;

	i = 0;
	while (i < arr_len)
	{
		curr = to_string(arr[i]);
		write(fd, curr, ft_strlen(curr));
		free(curr);
		write(fd, "\n", 1);
		i++;
	}
	write(fd, "\n", 1);
}
