/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:58:14 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 22:35:07 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_exec_recursive(t_list **head, t_data *data)
{
	int	p;

	p = fork();
	if (p == 0)
	{
		ft_nested_pip_ex((*head)->new_list->new_list, data, data->out,
			data->in);
		exit(1);
	}
	wait(NULL);
}

void	exec_utils(t_list *head, t_data *data, int fd1, int fd0)
{
	if (head->new_list->x != 4)
	{
		if (head->new_list->next)
		{
			pipe(data->fd);
			data->out = data->fd[1];
		}
		else
			data->out = fd1;
		if (head->new_list->x == 1)
		{
			ft_handel_redic(&head->new_list->redic, data, 1);
			if (head->new_list->int_file == 2)
				data->in = head->new_list->in;
			if (data->in == -1 || data->out == -1)
				return ;
			ft_exec_recursive(&head, data);
		}
		else
			ft_command(head->new_list, data);
		close_fd(&head, data, fd0);
	}
}

void	ft_nested_pip_ex(t_list *head, t_data *data, int fd1, int fd0)
{
	t_list	*tmp;

	data->exec = 0;
	while (head)
	{
		check_eo(head, data, fd1, fd0);
		if (data->exec == 0)
		{
			tmp = head->new_list;
			data->size = ft_lstsize(tmp);
			while (head->new_list)
			{
				exec_utils(head, data, fd1, fd0);
				head->new_list = head->new_list->next;
			}
			wait_proccess(data, data->pid);
		}
		head = head->next;
	}
}
