/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:57:29 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 20:20:12 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

// the length of  the randomization string
#define SEED_LEN 8

// the number of questions
#define NUM_QUES 16

// the length of the string " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define STR_LEN 63

// argv[1] the final output file
int		main(int argc, char **argv)
{
	unsigned int		arr_len;
	unsigned int		i_arr;
	unsigned int		arr_end;
	unsigned int		*arr;

	unsigned int		perm_list_max;
	unsigned int		perm_list_curr;
	t_perm				*list;

	char				*key;
	char				*seed;

	int 				fd;

	if (argc != 2)
	{
		printf("Usage: %s <output_file>\n", argv[0]);
		return (0);
	}

	fd = open(argv[1], O_WRONLY|O_CREAT, 0666);
	if (fd < 0)
	{
		printf("Error opening or creating file \"%s\"\n", argv[1]);
		return (0);
	}

	arr_len = 0;
	while (arr_len <= SEED_LEN)
	{
		i_arr = 0;
		arr = (unsigned int*)malloc(sizeof(unsigned int) * arr_len);
		while (i_arr < arr_len)
			arr[i_arr++] = 0;

		perm_list_max = factorial(arr_len);
		perm_list_curr = 0;
		list = (t_perm*)malloc(sizeof(t_perm) * perm_list_max);

		if (arr_len)
			while (arr[0] < STR_LEN)
			{
				arr_end = arr_len - 1;
				while (arr[arr_end] < STR_LEN)
				{
					key = init_key(NUM_QUES);
					seed = init_seed(arr_len, arr);
					shuffle(key, seed, arr_len);
					int loc = contains(list, key, perm_list_curr);
					if (loc == -1)
						list[perm_list_curr++] = init_perm(key);
					else
						list[loc].count++;
					free(key);
					free(seed);
					arr[arr_end]++;
				}
				while (arr[arr_end] == STR_LEN  && arr_end != 0) 
				{
					arr[arr_end] = 0;
					arr_end--;
					arr[arr_end]++;
				}
			}
		printf("Permutations done for seed length %i\n", arr_len);
		printf("List memory allocated: %i\nList memory used: %i\n\n", perm_list_max, perm_list_curr);
		save_permutations(list, perm_list_curr, fd);
		free(arr);
		cleanup(list, perm_list_curr);
		arr_len++;
	}
	close(fd);

	return (0);
}
