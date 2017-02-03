/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_questions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:18:44 by irhett            #+#    #+#             */
/*   Updated: 2017/02/03 00:19:31 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

//refactor this to remove "invalid" characters from a password string at the end of compilation?
char	*del_ws(char *str)
{
	int		index;
	int		len;
	char	*ans;

	len = 0;
	index = 0;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
			index++;
		len++;
	}
	ans = (char*)malloc(sizeof(char) * (index + 1));
	len = 0;
	index = 0;
	while (str[len])
	{
		if (ft_isalpha(str[len]))
		{
			if (ft_isupper(str[len]))
				ans[index] = str[len] + 32;
			else
				ans[index] = str[len];
			index++;
		}
		len++;
	}
	ans[index] = '\0';
	free(str);
	return (ans);
}

char	*security_questions(char **ques, int num_questions) //, char *file)
{
	int		i;
	char	*ans;
	char	*curr;

	ans = gnl_concat("", "", 0, 0);

	printf("Answer all the questions as accurately as possible.\n");
	printf("Answer what you are most likely to remember, not what is least likely to be guessed.\n");
	printf("If you cannot answer a question or it does not apply, put '0'\n");
	printf("Case is not sensitive.\n"); // TODO
	
	i = 0;
	while (i < num_questions)
	{
		printf("\n%s\n", ques[i]);
		free(ques[i]);
		get_next_line(STDIN_FILENO, &curr);
		//curr = del_ws(curr); 
		// 			removed for increased security. limiting to strict [a-z][A-Z][0-9] can be done later
		if (curr[0] == '\0')
		{
			free(curr);
			ans = gnl_concat(ans, "abcdefghijklmnopqrstuvwxyz", 1, 0); //improve this
			
		}
		else
		{
			ans = gnl_concat(ans, del_ws(curr), 1, 1);
			//write the answers to the security questions in another directory, aka (...char *file)
			//do this to add a second factor authentication when the device is used
			//
			// i.e: to obtain a password, enter your PIN and answer the following
			//  $(RANDOM security question)?
		}
		i++;
	}
	return (ans);
}
