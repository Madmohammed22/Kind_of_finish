/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:11:46 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 21:52:51 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"
#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(source);
	i = 0;
	dest = (char *)malloc(len + 1);
	ft_lstadd_back(&head_free, ft_lstnew_v1(dest));
	if (!dest)
		return (0);
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
