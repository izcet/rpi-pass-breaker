/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 23:13:03 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 23:22:13 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	cleanup(char **arr, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**copy(char **arr, int len)
{
	int		i;
	char	**dupe;

	i = 0;
	dupe = NULL;
	if (arr && (len > 0))
	{
		dupe = (char**)malloc(sizeof(char*) * len);
		while (i < len)
		{
			dupe[i] = gnl_concat(arr[i], "", 0, 0);
			i++;
		}
	}
	return (dupe);
}

char	*del_ws(char *str)
{
	int		index;
	int		len;
	char	*ans;

	len = 0;
	index = 0;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
			index++;
		len++;
	}
	ans = (char*)malloc(sizeof(char) * (index + 1));
	len = 0;
	index = 0;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
		{
			if (ft_isupper(str[len]))
				ans[index] = str[len] + 32;
			else
				ans[index] = str[len];
			index++;
		}
		len++;
	}
	ans[index] = '\0';
	free(str);
	return (ans);
}

char	*concat_strings(char **strs, int num)
{
	int		i;
	char	*ans;

	ans = gnl_concat("", "", 0, 0);
	i = 0;
	while (i < num)
	{
		ans = gnl_concat(ans, strs[i], 1, 0);
		free(strs[i]);
		i++;
	}
	return (ans);
}
