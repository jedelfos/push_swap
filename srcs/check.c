/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:51:43 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:19 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_max(t_var **list)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (i < 2)
	{
		list[i]->n_val = 0;
		temp = list[i]->first;
		list[i]->max = -1;
		list[i]->min = -1;
		while (temp != NULL)
		{
			if (temp->val > list[i]->max)
				list[i]->max = temp->val;
			if ((temp->val < list[i]->min) || (list[i]->min == -1))
				list[i]->min = temp->val;
			list[i]->n_val++;
			list[i]->last = temp;
			temp = temp->next;
		}
		i++;
	}
	return (0);
}

int	is_sort(t_var **list)
{
	t_list	*temp;

	temp = list[0]->first;
	while (temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	y;

	if (argc == 1)
		stop(1);
	i = 1;
	y = 0;
	while (argc > i)
	{
		while (argv[i][y] != '\0')
		{
			if (!(((argv[i][y] >= '0' && argv[i][y] <= '9')
				|| (argv[i][y] == '\t' || argv[i][y] == '\n'
				|| argv[i][y] == '\v' || argv[i][y] == '\f'
				|| argv[i][y] == '\r' || argv[i][y] == ' '
				|| argv[i][y] == '+' || argv[i][y] == '-'))))
				stop(1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}
