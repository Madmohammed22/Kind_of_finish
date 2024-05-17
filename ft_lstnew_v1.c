/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_v1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abquaoub <abquaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:44:47 by abquaoub          #+#    #+#             */
/*   Updated: 2024/05/16 18:46:20 by abquaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_initialize1(t_list *new_node)
{
	new_node->next = NULL;
	new_node->content = NULL;
	new_node->command = NULL;
	new_node->here_doc = NULL;
	new_node->new_list = NULL;
	new_node->redic = NULL;
	new_node->x = 0;
	new_node->int_file = 0;
	new_node->in = 0;
	new_node->out = 1;
}

t_list	*ft_lstnew_v1(void *content)
{
	t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->addr = content;
	ft_initialize1(new_node);
	return (new_node);
}