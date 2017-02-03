/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shuffle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:18:54 by irhett            #+#    #+#             */
/*   Updated: 2017/02/02 23:34:54 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

#define EXP1 (a - b) % n
#define EXP2 (b - a) % n

// refactor to improve security?
void	shuffle_n_strings(char **str, char *key, int n)
{
	int		i;

	i = 0;
	while (*key)
	{
		char	a = *key;
		char	b = *(key + 1);
			if (a > b)
				swap_str(&str[i], &str[EXP1]);
			else if (b > a)
				swap_str(&str[i], &str[EXP2]);
			else
				swap_str(&str[i], &str[0]);
		i++;
		if (i == n)
			i = 0;
		key++;
	}
	(void)str;
}
