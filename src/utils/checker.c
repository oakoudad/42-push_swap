/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakoudad <oakoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:38:34 by oakoudad          #+#    #+#             */
/*   Updated: 2022/04/02 21:05:20 by oakoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	valid_str(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->len - 1)
	{
		j = i + 1;
		while (j < data->len)
		{
			if (data->i_split[i] == data->i_split[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->len - 1)
	{
		if (data->i_split[i] < data->i_split[i + 1])
			j++;
		i++;
	}
	if (j == data->len - 1)
	{
		i = 0;
		while (data->s_split[i])
		{
			free(data->s_split[i]);
			i++;
		}
		free(data->s_split);
		free(data->i_split);
		return (0);
	}
	return (1);
}

void	checker(t_data *data, int c, char **v)
{
	char	*join;
	int		i;

	i = 1;
	join = NULL;
	while (i <= c - 1)
	{
		join = ft_strjoin(ft_strjoin(join, v[i++]), " ");
		if (!join)
			exit(0);
	}
	data->s_split = ft_split(join, ' ', &(data->len));
	data->i_split = malloc(sizeof(long) * data->len);
	if (!data->i_split)
		put_error("", data);
	check_numbers(data);
	i = 0;
	if (check_duplicate(data) == 0)
		put_error("Error\n", data);
}
