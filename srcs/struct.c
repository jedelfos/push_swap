/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:51:22 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/09 10:14:01 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_var	**list_m_param(t_var **list, int argc, char **argv)
{
	int	y;
	int	*val;

	y = 0;
	val = s_malloc(1, sizeof(int) * argc - 1);
	while (y < argc - 1)
	{
		val[y] = ft_atoi(argv[y + 1], 0);
		y++;
	}
	ft_sort_int_tab(val, argc - 1);
	y = 1;
	while (y < argc)
	{
		ft_lstadd_back(list[0], ft_atoi(argv[y], 0), val);
		y++;
	}
	return (list);
}

t_var	**create_list(int argc, char **argv)
{
	t_var	**list;
	int		y;

	y = 0;
	list = s_malloc(1, sizeof(t_var *) * 2);
	list[0] = s_malloc(1, sizeof(t_var));
	list[0]->first = NULL;
	list[0]->last = NULL;
	list[1] = s_malloc(1, sizeof(t_var));
	list[1]->first = NULL;
	list[1]->last = NULL;
	list_m_param(list, argc, argv);
	return (list);
}
