/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:19:07 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:55 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	cherche(t_var *list, int num)
{
	t_list	*temp;
	int		i;
	int		y;

	temp = list->first;
	i = 1;
	y = 1;
	while (temp->next && temp->val != num)
	{
		i++;
		temp = temp->next;
	}
	temp = list->last;
	while (temp->prec && temp->val != num)
	{
		y ++;
		temp = temp->prec;
	}
	if (i <= y)
		return (i);
	return (y * -1);
}

int	main(int argc, char **argv)
{
	t_var	**list;
	int		place;

	check_argv(argc, argv);
	list = (t_var **)create_list(argc, argv);
	if (is_sort(list))
		stop(0);
	low_check(list);
	while (list[0]->first->next != NULL)
	{
		min_max(list);
		place = calc_score(list);
		positionement(list, place);
	}
	pb(list);
	min_max(list);
	while (list[1]->n_val > 1)
	{
		min_max(list);
		place = cherche(list[1], list[1]->max);
		positionement_final(list, place);
	}
	s_malloc (0, 0);
	return (0);
}
