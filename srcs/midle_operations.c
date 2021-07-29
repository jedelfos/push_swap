/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midle_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:50:08 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:09:01 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rb(t_var **list)
{
	t_list	*temp;

	list[0]->coup++;
	write (1, "rb\n", 3);
	temp = list[1]->first;
	list[1]->first = list[1]->first->next;
	list[1]->first->prec = NULL;
	temp->next = NULL;
	list[1]->last->next = temp;
	temp->prec = list[1]->last;
	list[1]->last = temp;
	return (0);
}

int	rr(t_var **list)
{
	write (1, "rr\n", 3);
	ra(list);
	rb(list);
	return (0);
}

int	rra(t_var **list)
{
	t_list	*temp;

	list[0]->coup++;
	write (1, "rra\n", 4);
	temp = list[0]->last;
	list[0]->last = list[0]->last->prec;
	list[0]->last->next = NULL;
	temp->prec = NULL;
	temp->next = list[0]->first;
	list[0]->first->prec = temp;
	list[0]->first = temp;
	return (0);
}

int	rrb(t_var **list)
{	
	t_list	*temp;

	write (1, "rrb\n", 4);
	list[0]->coup++;
	temp = list[1]->last;
	list[1]->last = list[1]->last->prec;
	list[1]->last->next = NULL;
	temp->prec = NULL;
	temp->next = list[1]->first;
	list[1]->first->prec = temp;
	list[1]->first = temp;
	return (0);
}
