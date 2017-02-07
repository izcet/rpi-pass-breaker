/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:48:34 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 10:48:38 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*init_ans(unsigned int len)
{
	char			ret;
	unsigned int	i;
	char			c;


	ret = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	c = 'a';
	while (i < len)
	{
		ret[i] = c;
		i++;
		c++;
	}
	ret[len] = '\0';
	return (ret);
}
