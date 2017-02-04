/* ************************************************************************** */
/*                                                                            */
/*                                                         :::      ::::::::   */
/*   make_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:51:26 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 23:25:06 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*make_seed(char *range, int len, int *nums)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		ret[i] = range[nums[i]];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

