/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:18:54 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 13:04:00 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

#define EXP1 (a - b) % n
#define EXP2 (b - a) % n

void	shuffle(char *seed, char *key, int n)
{
	int		i;

	i = 0;
	while (*key)
	{
		char	a = *key;
		char	b = *(key + 1);
			if (a > b)
				swap_char(&seed[i], &seed[EXP1]);
			else if (b > a)
				swap_char(&seed[i], &seed[EXP2]);
			else
				swap_char(&seed[i], &seed[0]);
		i++;
		if (i == n)
			i = 0;
		key++;
	}
	(void)seed;
}
