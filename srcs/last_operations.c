/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:50:20 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:36 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rrr(t_var **list)
{
	write (1, "rrr\n", 4);
	rra(list);
	rrb(list);
	return (0);
}

int	pa(t_var **list)
{
	t_list	*temp;

	write (1, "pa\n", 3);
	list[0]->coup++;
	temp = list[1]->first;
	list[1]->first = temp->next;
	if (list[1]->first)
		list[1]->first->prec = NULL;
	else
		list[1]->last = NULL;
	if (list[0]->first != NULL)
		list[0]->first->prec = temp;
	temp->prec = NULL;
	temp->next = list[0]->first;
	list[0]->first = temp;
	if (temp ->next == NULL)
		list[0]->last = temp;
	return (0);
}

int	pb(t_var **list)
{
	t_list	*temp;

	write (1, "pb\n", 3);
	list[0]->coup++;
	temp = list[0]->first;
	list[0]->first = temp->next;
	if (list[0]->first)
		list[0]->first->prec = NULL;
	else
		list[0]->last = NULL;
	if (list[1]->first != NULL)
		list[1]->first->prec = temp;
	temp->prec = NULL;
	temp->next = list[1]->first;
	list[1]->first = temp;
	if (temp ->next == NULL)
		list[1]->last = temp;
	return (0);
}
