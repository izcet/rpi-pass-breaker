/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 05:12:02 by irhett            #+#    #+#             */
/*   Updated: 2017/02/04 00:18:09 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

/*char	*get_known(char *arr)
{


}*/

char	*make_dir_str(char *dir,  char *name, char *seed)
{
	char	*ans;

	ans = gnl_concat(dir, "/", 0, 0);
	//ans = gnl_concat(ans, name, 1, 0);
	//ans = gnl_concat(ans, "/", 1, 0);
	ans = gnl_concat(ans, name, 1, 0);
	ans = gnl_concat(ans, "-", 1, 0);
	ans = gnl_concat(ans, seed, 1, 0);
	return (ans);
}
