/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmad <mmad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:33:37 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/17 15:49:11 by mmad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define EXTERN
#include "ft_minishell.h"

int		mode;

void	handle_signal(int sig)
{
	if (sig == SIGINT && mode == 0)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	ft_handle_signals(void)
{
	if (signal(SIGINT, handle_signal) == SIG_ERR)
		printf("Error catch signal\n");
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_data	data;
	t_list	*head;
	t_list	*tmp;

	head_free = NULL;
	head_list = NULL;
	(void)av;
	head = NULL;
	data.env = env;
	initialize(NULL, &data);
	ft_buffer_to_list(&data.env_list, env);
	if (ac != 1)
		return (1);
	while (1)
	{
		mode = 0;
		ft_handle_signals();
		line = ft_pwd(0);
		line = readline(line);
		add_history(line);
		if (!line)
			break ;
		(void)head;
		ft_syntax(line, &data);
		if (data.red == 1)
		{
			ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
			data.red = 0;
		}
		else
		{
			mode = 1;
			head = ft_nested_pip(line, &data);
			ft_nested_pip_ex(head, &data, STDOUT_FILENO, STDIN_FILENO);
			// data.in = 0;
			// data.out = 1;
		}
	}
	tmp = NULL;
	while (head_free)
	{
		tmp = head_free->next;
		free(head_free->addr);
		ft_lstdelone(head_free, free);
		head_free = tmp;
	}
	return (0);
}
