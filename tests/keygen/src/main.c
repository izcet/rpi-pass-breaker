/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keygen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:29:29 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 05:33:27 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

//seed_known/known-01/keylen-02
//			01-20		00-16

#define SRCDIR seed_known

int		main(int argc, char **argv)
{
	int		num_que;
	int		num_ans;
	char	**que;
	char	**ans;

	if (argc != 4)
	{
		printf("\nInternal error invalid input to executable \"%s\"\n", argv[0]);
		return (0);
	}

	que = read_list(argv[1], &num_que);
	if (!que)
	{
		printf("Error opening question file \"%s\"\n", argv[1]);
		return (0);
	}

	ans = read_list(argv[2], &num_ans);
	if (!ans)
	{
		printf("Error opening answer file \"%s\"\n", argv[2]);
		cleanup(que, num_que);
		return (0);
	}

	shuffle_n_strings(questions, argv[1], index);
	ans = security_questions(questions, index);

	fd = open(argv[3], O_WRONLY|O_CREAT, 0444);
	if (fd == -1)
	{
		printf("\nInternal error creating key file \"%s\" from executable \"%s\".\n", argv[3], argv[0]);
		printf("The key is:\n\n");
		printf("%s\n", ans);
	}
	else
	{
		write(fd, ans, ft_strlen(ans));
		close(fd);
	}

	free(ans);
	free(questions);
	return (0);
}
