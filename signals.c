/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:41:17 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/13 16:43:02 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// void	handle_signal(int sig)
// {
// 	if (sig == SIGINT && data_mode == 0)
// 	{
// 		printf("\n");
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// 	else
// 	{
// 		printf("\n");
// 		rl_replace_line("", 0);
// 		rl_on_new_line();

// 	}
// }
// void	handle_signal_cat(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		printf("\n");
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 	}
// }
// void	ft_handle_signals(void)
// {
// 	if (signal(SIGINT, handle_signal) == SIG_ERR)
// 		printf("Error catch signal\n");
// 	signal(SIGINT, handle_signal);
// 	// if (data->data_mode == 0)
// 	// else if (data->data_mode == 1)
// 	// 	signal(SIGINT, handle_signal_cat);
// 	signal(SIGQUIT, SIG_IGN);
// 	signal(SIGTERM, SIG_IGN);
// }