/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 22:19:08 by irhett            #+#    #+#             */
/*   Updated: 2017/02/02 22:19:11 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_str(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	swap_char(char *c1, char *c2)
{
	char	temp;
	
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}
