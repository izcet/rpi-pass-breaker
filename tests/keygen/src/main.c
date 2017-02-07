/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:57:29 by irhett            #+#    #+#             */
/*   Updated: 2017/02/07 13:03:48 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

// the length of  the randomization string
#define SEED_LEN 8

// the number of questions
#define NUM_QUES 16

// argv[1] the final output file
int		main(int argc, char **argv)
{
	unsigned int		arr_len;
	unsigned int		i_arr;
	unsigned int		arr_end;

	unsigned int		*arr;

	if (argc != 2)
	{
		printf("Usage: %s <output_file>\n", argv[0]);
		return (0);
	}

	i_len = 0;
	while (arr_len <= SEED_LEN)
	{
		i_arr = 0;
		arr = (int*)malloc(sizeof(int) * arr_len);
		while (i_arr < i_len)
			arr[i_arr++] = 0;

		if (arr_len > 0)
		{
			while (arr[0] <= arr_len)
			{
				arr_end = arr_len - 1;
				while (arr[arr_end] <= arr_len)
				{
					//seed = make_seed(RANGE, seed_i, nums);
					//shuffle(temp_ans, seed, num_answers);


					// TODO move open file outside loop and only write lines at the end. use this space to add data to
					// the permutations structure

				//	fd = open(file, O_WRONLY|O_CREAT, 0444);
					if (fd == -1)
						printf("File \"%s\" not made.\n", file); //, key was \"%s\"\n", file, key);
					else
					{
						write(fd, key, ft_strlen(key));
						close(fd);
					}

					free(key);
					free(file);
					free(seed);
					free(temp_ans);

					nums[last_num]++;
				}
				while (nums[last_num] == RANGE_LEN && last_num != 0) 
				{
					nums[last_num] = 0;
					last_num--;
					nums[last_num]++;
				}
			}
		}
		else
		{
			// permutate 0 times
			// do stuff exactly once,

		}

	}

	return (0);
}
