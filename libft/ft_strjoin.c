/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:01:35 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 21:55:10 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_lstadd_back(&head_free, ft_lstnew_v1(res));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2 && s2[j])
		{
			res[i + j] = s2[j];
			j++;
		}
	}
	res[i + j] = 0;
	return (res);
}
