/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 05:15:13 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 05:23:44 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char		**read_list(char *file, int *num)
{
	int		fd;
	int		gnl;
	char	**ans;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	gnl = 1;
	*num = 0;
	ans = (char**)malloc(sizeof(char*) * 128);
	while (gnl)
	{
		gnl = get_next_line(fd, &ans[num++]);
		if (gnl > 0)
			*num++;
	}
	close(fd);

	return (ans);
}
