/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:49:51 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 21:56:21 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_nested_syntax(t_list **head, t_data *data, int *flag)
{
	char		*cmd;
	t_quotes	qutes;
	t_list		*list;
	t_list		*ss;

	list = *head;
	ss = split_end_or(list->content, "<> ", 0);
	*flag = ft_check_syntax(ss, 2, data);
	if (!(*flag))
		ft_split_rediction(list->content, head);
	cmd = join_command(list->command);
	if (cmd && !data->red)
	{
		ft_check_string(cmd, data);
		if (ft_count_qutes(cmd, &qutes) == 1 && !data->red)
		{
			cmd = ft_substr(cmd, 1, ft_strlen(cmd) - 2);
			ft_syntax(cmd, data);
		}
	}
}

void	ft_syntax(char *line, t_data *data)
{
	t_list	*head;
	t_list	*list;

	head = split_end_or(line, "|& ", 1);
	data->red = ft_check_syntax(head, 4, data);
	while (head && !data->red)
	{
		if (head->x != 4)
		{
			list = split_end_or(head->content, "|", 0);
			data->red = ft_check_syntax(list, 4, data);
			while (list && !data->red)
			{
				if (list->x != 4)
					ft_nested_syntax(&list, data, &data->red);
				list = list->next;
			}
		}
		head = head->next;
	}
}

int	ft_check_syntax(t_list *head, int flag, t_data *data)
{
	int			i;
	t_list		*tmp;
	int			value;
	int			j;
	t_quotes	qutes;
	int			save;

	value = 0;
	i = 0;
	save = 0;
	tmp = head;
	while (head && !value)
	{
		if (head->x == 2)
			save = 1;
		if ((head->x == flag && (!head->next || head->next->x == flag))
			|| (head->x == 4 && i == 0))
			value = 1;
		if (save && ft_count_qutes(head->content, &qutes))
			value = 1;
		head = head->next;
		i++;
	}
	j = 0;
	while (tmp && value == 1)
	{
		if (!strcmp(tmp->content, "<<") && tmp->next && flag == 2 && j < i)
			ft_read_stdin(tmp->next->content, data);
		j++;
		tmp = tmp->next;
	}
	return (value);
}

void	ft_check_string(char *line, t_data *data)
{
	int			i;
	t_quotes	qutes;

	i = 0;
	initialize(&qutes, NULL);
	while (line[i])
	{
		ft_check_quotes(line[i], &qutes);
		i++;
	}
	if (qutes.cp || qutes.cq || qutes.cs || (qutes.en % 2) || (qutes.bk % 2))
		data->red = 1;
}

int	ft_check_wildcard(char *line)
{
	int			i;
	t_quotes	qutes;

	i = 0;
	initialize(&qutes, NULL);
	while (line[i])
	{
		ft_check_quotes(line[i], &qutes);
		if (qutes.cq || qutes.cs)
			return (1);
		i++;
	}
	return (0);
}
