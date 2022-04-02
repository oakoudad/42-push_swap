/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:01:33 by oakoudad          #+#    #+#             */
/*   Updated: 2022/04/02 17:21:01 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_opirations(char *cmd)
{
	if (ft_strcmp(cmd, "sa\n") && ft_strcmp(cmd, "sb\n")
		&& ft_strcmp(cmd, "ss\n") && ft_strcmp(cmd, "pa\n")
		&& ft_strcmp(cmd, "pb\n") && ft_strcmp(cmd, "ra\n")
		&& ft_strcmp(cmd, "rb\n") && ft_strcmp(cmd, "rr\n")
		&& ft_strcmp(cmd, "rra\n") && ft_strcmp(cmd, "rrb\n")
		&& ft_strcmp(cmd, "rrr\n"))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

void	ft_action(t_list **a, t_list **b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap(b);
	else if (!ft_strcmp(cmd, "ss\n"))
		ss_(a, b);
	else if (!ft_strcmp(cmd, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(cmd, "rr\n"))
		rr_(a, b);
	else if (!ft_strcmp(cmd, "rra\n"))
		reverse(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		reverse(b);
	else if (!ft_strcmp(cmd, "rrr\n"))
		rrr_(a, b);
}

void	check_args(t_data *data, int c, char **v)
{
	char	*join;
	int		i;

	i = 1;
	join = NULL;
	if (c <= 1)
		exit(1);
	while (i <= c - 1)
	{
		join = ft_strjoin(ft_strjoin(join, v[i++]), " ");
		if (!join)
			exit(1);
	}
	data->s_split = ft_split(join, ' ');
	data->len = i - 1;
	data->i_split = malloc(sizeof(long) * i);
	if (!data->i_split)
		put_error("", data);
	check_numbers(data);
	if (check_duplicate(data) == 0)
		put_error("Error\n", data);
}

int	create_list(t_list **lst, t_data *data)
{
	int		i;
	t_list	*stack;
	t_list	*new;

	i = 0;
	stack = NULL;
	while (i < data->len)
	{
		new = ft_lstnew(data->i_split[i]);
		if (!new)
			return (0);
		ft_lstadd_back(&stack, new);
		i++;
	}
	*lst = stack;
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*a;
	t_list	*b;
	char	buff[5];

	if (ac == 1)
		return (0);
	check_args(&data, ac, av);
	if (create_list(&a, &data) == 0)
		free_all(&a, &b, &data);
	while (read(0, buff, 4))
	{
		check_opirations(buff);
		ft_action(&a, &b, buff);
		ft_zero(buff);
	}
	if (check_sorted(a) && ft_lstsize(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(&a, &b, &data);
	return (0);
}
