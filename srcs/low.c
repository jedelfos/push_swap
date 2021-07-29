/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:52:10 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:18:40 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	very_low_nb_utils(t_var **list)
{
	if (list[0]->first->next->val == 1)
		ra(list);
	else
	{
		sa(list);
		rra(list);
	}
	return (0);
}

int	very_low_nb(t_var **list)
{
	if (list[0]->n_val == 2)
		sa(list);
	else if (list[0]->first->val == 1)
	{
		ra(list);
		if (list[1]->first != NULL && list[1]->first->val == 5)
		{
			ss(list);
		}
		else
			sa(list);
		rra(list);
	}
	else if (list[0]->first->val == 2)
	{
		if (list[0]->first->next->val == 1)
			sa(list);
		else
			rra(list);
	}
	else if (list[0]->first->val == 3)
		very_low_nb_utils(list);
	if (list[1]->n_val == 0)
		stop (0);
	return (0);
}

int	low_nb(t_var **list)
{
	while (list[0]->n_val > 3)
	{
		if (list[0]->first->val == 5 || list[0]->first->val == 4)
			pb(list);
		else
			ra(list);
		min_max(list);
	}
	if (!(is_sort(list)))
		very_low_nb(list);
	min_max(list);
	if (list[1]->first != NULL && list[1]->first->val == 5)
		sb(list);
	pa(list);
	ra(list);
	min_max(list);
	if (list[1]->first != NULL && list[1]->first->val == 5)
	{
		pa(list);
		ra(list);
	}
	stop (0);
	return (0);
}

int	low_check(t_var **list)
{
	min_max(list);
	list[0]->coup = 0;
	if (list[0]->n_val > 5)
		return (0);
	if (list[0]->n_val <= 3)
		very_low_nb(list);
	low_nb(list);
	return (0);
}
