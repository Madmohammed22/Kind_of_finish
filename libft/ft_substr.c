/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:29:45 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 21:56:16 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	else if (ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = (char *)malloc(len + 1);
	ft_lstadd_back(&head_free, ft_lstnew_v1(res));
	if (!res)
		return (0);
	while (s[start] != '\0' && j < len)
	{
		res[j] = s[start];
		j++;
		start++;
	}
	res[j] = '\0';
	return (res);
}
