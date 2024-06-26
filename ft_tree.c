/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:27:06 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 22:15:34 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_math(int i)
{
	int	number;

	number = 1;
	while (i)
	{
		number *= 2;
		i--;
	}
	return (number);
}

int	ft_reverse(char *str)
{
	int	number;
	int	i;

	str = &str[7];
	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			number += ft_math(7 - i);
		i++;
	}
	return (number);
}

char	*ft_revers_to_base64(char *str)
{
	char	*join;
	int		i;

	join = NULL;
	i = 0;
	while (str[i])
	{
		join = ft_new_strjoin(join, ft_reverse(ft_substr(str, i, 8)));
		i += 8;
	}
	return (join);
}

char	*join_command(t_list *head)
{
	char	*join;

	join = NULL;
	while (head)
	{
		join = ft_strjoin(join, head->content);
		if (head->next)
			join = ft_strjoin(join, " ");
		head = head->next;
	}
	return (join);
}

void	ft_nested(t_list *head, t_data *data)
{
	char		*cmd;
	char		*save;
	t_quotes	qutes;
	t_list		*list;

	save = NULL;
	list = head;
	ft_split_rediction(list->content, &(list));
	cmd = join_command(list->command);
	if (cmd)
	{
		if (ft_count_qutes(cmd, &qutes) == 1)
		{
			list->x = 1;
			save = ft_substr(cmd, 1, ft_strlen(cmd) - 2);
			list->new_list = ft_nested_pip(save, data);
		}
	}
	list->command = ft_handel_qutes(list->command, data, 0);
	list->redic = ft_handel_qutes(list->redic, data, 0);
	list->here_doc = ft_handel_qutes(list->here_doc, data, 1);
	ft_handel_redic(&(list->here_doc), data, 0);
	list->in = data->in;
}

t_list	*ft_nested_pip(char *line, t_data *data)
{
	t_list	*head;
	t_list	*new;
	t_list	*list;

	head = split_end_or(line, "|&", 1);
	new = head;
	while (head)
	{
		if (!head->x)
		{
			list = split_end_or(head->content, "|", 0);
			head->new_list = list;
			while (list)
			{
				if (list->x != 4)
					ft_nested(list, data);
				list = list->next;
			}
		}
		head = head->next;
	}
	return (new);
}
