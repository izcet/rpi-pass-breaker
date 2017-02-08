/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:18:54 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 19:09:37 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

#define EXP1 (a - b) % n
#define EXP2 (b - a) % n

void	shuffle(char *key, char *seed, int n)
{
	int		i;

	i = 0;
	while (*seed)
	{
		char	a = *seed;
		char	b = *(seed + 1);
			if (a > b)
				swap_char(&key[i], &key[EXP1]);
			else if (b > a)
				swap_char(&key[i], &key[EXP2]);
			else
				swap_char(&key[i], &key[0]);
		i++;
		if (i == n)
			i = 0;
		seed++;
	}
	(void)key;
}
