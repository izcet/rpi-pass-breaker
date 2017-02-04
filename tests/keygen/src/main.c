/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:57:29 by irhett            #+#    #+#             */
/*   Updated: 2017/02/04 00:29:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

//seed_known/known-01/keyseed_i-02
//			01-20		00-16

#define SRCDIR seed_known
#define MAX_SEED_LEN 8 
#define RANGE "abcdefgh" 
#define RANGE_LEN 8

int		main(int argc, char **argv)
{	
	char	**answers_source;
	char	**temp_ans;
	int		num_answers; // 20

	int		seed_i; // 0 -> 16
	int		index;

	int		fd;
	char	*file;

	int		*nums;
	int		last_num;
	char	*seed;	//the randomization factor
	char	*key; // what is written to the file

	if (argc != 3) // argv[0] answer_file output_directory
	{
		printf("Usage: %s <answer_file> <output_directory>\n", argv[0]);
		return (0);
	}

	answers_source = read_list(argv[1], &num_answers);
	if (!answers_source)
	{
		printf("Error opening answer file \"%s\"\n", argv[1]);
		return (0);
	}
	printf("answer file read\n");

	seed_i = 1;
	while (seed_i <= MAX_SEED_LEN)
	{
		printf("seed_i = %i\n", seed_i);
		nums = (int*)malloc(sizeof(int) * MAX_SEED_LEN);
		index = 0;
		while (index < MAX_SEED_LEN)
			nums[index++] = 0;

		while (nums[0] < RANGE_LEN)
		{

			last_num = seed_i - 1;
			//printf("last_num = %i\n", last_num);
			while (nums[last_num] < RANGE_LEN)
			{
				temp_ans = copy(answers_source, num_answers);
				seed = make_seed(RANGE, seed_i, nums);
				//printf("Seed is \"%s\"\n", seed);
				shuffle_n_strings(temp_ans, seed, num_answers);

				key = concat_strings(temp_ans, num_answers);

				file = make_dir_str(argv[2], argv[1], seed);
				fd = open(file, O_WRONLY|O_CREAT, 0444);
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
		seed_i++;
		free(nums);
	}

	cleanup(answers_source, num_answers);
	return (0);
}
