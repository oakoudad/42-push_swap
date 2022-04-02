/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:13:59 by oakoudad          #+#    #+#             */
/*   Updated: 2022/03/28 11:14:17 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_pos(t_list *stack, int sort_pos)
{
	int	pos;

	pos = 0;
	while (stack && stack->index != sort_pos)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_min_dis(int size, int pos)
{
	int	dis_from_top;
	int	dis_from_bot;

	dis_from_top = pos;
	dis_from_bot = size - pos;
	if (dis_from_top < dis_from_bot)
		return (dis_from_top);
	return (dis_from_bot);
}

void	take_to_top(t_list **stack, int pos, int sort_pos, int size)
{
	if (pos <= (size / 2))
		while ((*stack) && (*stack)->index != sort_pos)
			rb(stack);
	else
		while ((*stack) && (*stack)->index != sort_pos)
			rrb(stack);
}
