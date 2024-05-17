/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 01:37:39 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/17 09:44:27 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_check_command(t_data *data, char *command)
{
	char	*path;
	t_list	*head;
	char	*cmd;

	path = ft_getenv(data, "PATH");
	if (path && !ft_strrchr(command, '/') && command[0] && !ft_strrchr(command,
			'.'))
	{
		head = split_end_or(path, ":", 0);
		cmd = ft_strjoin("/", command);
		while (head)
		{
			if (head->x == 0)
			{
				path = ft_strjoin(head->content, cmd);
				if (access(path, F_OK) == 0)
					return (path);
			}
			head = head->next;
		}
	}
	return (ft_strdup(command));
}

void	ft_display(t_list *ptr)
{
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	while (ptr)
	{
		printf("[%s]\n", (char *)ptr->content);
		ptr = ptr->next;
	}
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}
