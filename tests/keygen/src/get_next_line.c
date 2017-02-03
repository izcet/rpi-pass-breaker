/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:18:35 by irhett            #+#    #+#             */
/*   Updated: 2017/02/02 22:18:41 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*gnl_concat(char *str1, char *str2, int mall_1, int mall_2)
{
	int		len1;
	int		len2;
	char	*ans;

	len1 = 0;
	len2 = 0;
	while (str1[len1])
		len1++;
	while (str2[len2])
		len2++;
	ans = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	len1 = -1;
	len2 = -1;
	while (str1[++len1])
		ans[len1] = str1[len1];
	while (str2[++len2])
		ans[len1 + len2] = str2[len2];
	if (mall_1)
		free(str1);
	if (mall_2)
		free(str2);
	ans[len1 + len2] = '\0';
	return (ans);
}

int				gnl_scan(char *str, int newline)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n' && newline)
			return (index);
		index++;
	}
	if (newline)
		return (-1);
	return (index);
}

int				gnl_copy(char *src, char **dst, char **stat, int fd)
{
	int		index;
	int		len;
	int		ret;

	ret = 0;
	len = 0;
	while ((src[len] != '\n') && (src[len] != '\0'))
		len++;
	dst[0] = (char*)malloc(sizeof(char) * len + 1);
	index = 0;
	while ((src[index] != '\n') && (src[index] != '\0'))
	{
		dst[0][index] = src[index];
		index++;
	}
	dst[0][index] = '\0';
	if (src[index] == '\n')
	{
		ret = 1;
		stat[fd] = gnl_concat(&(src[++index]), "", 0, 0);
	}
	free(src);
	return (ret);
}

static int		cleanup(char **stat, int fd, char *buff, char *ret)
{
	if (stat[fd])
		free(stat[fd]);
	free(buff);
	free(ret);
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stat[15000];
	int				br;
	char			*buffer;
	char			*ret;

	br = 1;
	if (fd < 0 || (line == NULL) || BUFF_SIZE <= 0)
		return (-1);
	if (stat[fd] != NULL)
		ret = gnl_concat(stat[fd], "", 1, 0);
	else
		ret = gnl_concat("", "", 0, 0);
	stat[fd] = NULL;
	while ((gnl_scan(ret, 1) == -1) && br)
	{
		buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		br = read(fd, buffer, BUFF_SIZE);
		if (br == -1)
			return (cleanup(stat, fd, buffer, ret));
		buffer[br] = '\0';
		ret = gnl_concat(ret, buffer, 1, 1);
	}
	if ((gnl_copy(ret, line, stat, fd) == 0) && (br == 0) && (gnl_scan(ret, 0) == 0))
		return (0);
	return (1);
}
