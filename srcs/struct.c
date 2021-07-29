/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:51:22 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:18:58 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_var	**list_m_param(t_var **list, int argc, char **argv)
{
	int	y;
	int	*val;

	y = 0;
	val = s_malloc(1, sizeof(int) * argc);
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

t_var	**list_s_param_utils(t_var **list, char **argv, int *val, int i)
{
	int	y;
	int	u;

	u = 0;
	y = 0;
	while (u != -1)
	{
		val[y] = ft_atoi(argv[1], u);
		u = skip_word(argv[1], u);
		y++;
	}
	ft_sort_int_tab(val, i - 1);
	u = 0;
	while (u != -1)
	{
		ft_lstadd_back(list[0], ft_atoi(argv[1], u), val);
		u = skip_word(argv[1], u);
	}
	return (list);
}

t_var	**list_s_param(t_var **list, char **argv)
{
	int	y;
	int	i;
	int	*val;

	y = 0;
	i = 1;
	while (y != -1)
	{
		y = skip_word(argv[1], y);
		i++;
	}
	val = s_malloc(1, sizeof(int) * i);
	list = list_s_param_utils(list, argv, val, i);
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
	if (argc > 2)
		list_m_param(list, argc, argv);
	else
		list_s_param(list, argv);
	return (list);
}
