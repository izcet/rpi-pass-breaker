/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:20:09 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 20:14:05 by irhett           ###   ########.fr       */
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

t_perm				init_perm(char *str);
int					contains(t_perm *list, char *str, int len);
void				cleanup(t_perm *list, int len);
char				*to_string(t_perm elem);
void				save_permutations(t_perm *arr, unsigned int len, int fd);

int					ft_isalpha(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isdigit(int c);
int					ft_isrange(int c, char *str);

unsigned long		factorial(unsigned int x);
unsigned int		ft_strlen(char *str);
int					ft_strequ(char *s1, char *s2);
char				*ft_itoa(int n);

void				shuffle(char *str, char *key, int n);

void				swap_str(char **str1, char **str2);
void				swap_char(char *c, char *d);

char				*init_key(unsigned int len);
char				*init_seed(int len, unsigned int *nums);

/*void				cleanup(char **arr, int len);
char				**copy(char **arr, int len);
char				*del_ws(char *str);
char				*concat_strings(char **strs, int num);
*/

#endif
