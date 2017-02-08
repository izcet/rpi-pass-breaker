/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:17:12 by irhett            #+#    #+#             */
/*   Updated: 2017/02/02 22:21:33 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

char	*gnl_concat(char *s1, char *s2, int b1, int b2);
int		gnl_scan(char *s, int b);
int		gnl_copy(char *s, char **d, char **st, int fd);

int		get_next_line(const int fd, char **line);

#endif
