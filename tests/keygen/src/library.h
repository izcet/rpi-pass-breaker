/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:20:09 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 13:03:55 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

typedef struct 		permutation
{
	char			*str;
	unsigned int	count;
}					t_perm;

int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isrange(int c, char *str);

unsigned long		factorial(unsigned int x);
unsigned int		ft_strlen(char *str);

void				shuffle(char *str, char *key, int n);
char				*make_seed(char *range, int len, int *nums);

void				swap_str(char **str1, char **str2);
void				swap_char(char *c, char *d);

void				cleanup(char **arr, int len);
char				**copy(char **arr, int len);
char				*del_ws(char *str);
char				*concat_strings(char **strs, int num);

#endif
