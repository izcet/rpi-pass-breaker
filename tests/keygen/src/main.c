/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keygen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:29:29 by irhett            #+#    #+#             */
/*   Updated: 2017/02/02 23:34:59 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

// TODO add the argv[] for the output file for the Q&A 2FA
int		main(int argc, char **argv)
{
	int		fd;
	int		gnl;
	int		index;
	char	**questions;
	char	*ans;

	if (argc != 4)
	{
		printf("\nInternal error invalid input to executable \"%s\"\n", argv[0]);
		return (0);
	}

	fd = open(argv[2], O_RDONLY);
	if (fd == -1)
	{
		printf("\nInternal error in executable \"%s\" opening question source file \"%s\".\n", argv[0], argv[2]);
		return (0);
	}

	index = 0;
	gnl = 1;
	questions = (char**)malloc(sizeof(char*) * 128); // i think 128 is a safe upper bound for the number of security questions
	while (gnl)
	{
		gnl = get_next_line(fd, &questions[index]);
		if (gnl > 0)
			index++;
	}
	close(fd);
	
	shuffle_n_strings(questions, argv[1], index);
	ans = security_questions(questions, index);

	fd = open(argv[3], O_WRONLY|O_CREAT, 0440);
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
