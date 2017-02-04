/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:20:09 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 23:32:02 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_KEY_H
#define MAKE_KEY_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isdigit(int c);
int				ft_isrange(int c, char *str);

unsigned int	ft_strlen(char *str);

char			*security_questions(char **qs, int num_q); //, char *file);
void			shuffle_n_strings(char **str, char *key, int n);
char			**read_list(char *file, int *num);
char			*make_seed(char *range, int len, int *nums);

void			swap_str(char **str1, char **str2);
void			swap_char(char *c, char *d);

void			cleanup(char **arr, int len);
char			**copy(char **arr, int len);
char			*del_ws(char *str);
char			*concat_strings(char **strs, int num);

char			*make_dir_str(char *dir, char *name, char *seed);

#endif
