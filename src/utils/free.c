/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:10:47 by oakoudad          #+#    #+#             */
/*   Updated: 2022/04/02 17:23:04 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	free_all(t_list **a, t_list **b, t_data *data)
{
	int	i;

	free_list(a);
	free_list(b);
	i = 0;
	while (data->s_split[i])
	{
		free(data->s_split[i]);
		i++;
	}
	free(data->s_split);
	free(data->i_split);
}
