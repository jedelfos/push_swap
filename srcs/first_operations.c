/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:49:50 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:28 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_var **list)
{
	t_list	*temp;

	write (1, "sa\n", 3);
	list[0]->coup++;
	temp = list[0]->first->next;
	list[0]->first->next = temp->next;
	list[0]->first->prec = temp;
	temp->next = list[0]->first;
	temp->prec = NULL;
	list[0]->first = temp;
	return (0);
}

int	sb(t_var **list)
{
	t_list	*temp;

	write (1, "sb\n", 3);
	list[0]->coup++;
	temp = list[1]->first->next;
	list[1]->first->next = temp->next;
	list[1]->first->prec = temp;
	temp->next = list[1]->first;
	temp->prec = NULL;
	list[1]->first = temp;
	return (0);
}

int	ss(t_var **list)
{
	t_list	*temp;

	write (1, "ss\n", 3);
	list[0]->coup++;
	temp = list[0]->first->next;
	list[0]->first->next = temp->next;
	list[0]->first->prec = temp;
	temp->next = list[0]->first;
	temp->prec = NULL;
	list[0]->first = temp;
	temp = list[1]->first->next;
	list[1]->first->next = temp->next;
	list[1]->first->prec = temp;
	temp->next = list[1]->first;
	temp->prec = NULL;
	list[1]->first = temp;
	return (0);
}

int	ra(t_var **list)
{	
	t_list	*temp;

	write (1, "ra\n", 3);
	list[0]->coup++;
	temp = list[0]->first;
	list[0]->first = list[0]->first->next;
	list[0]->first->prec = NULL;
	temp->next = NULL;
	list[0]->last->next = temp;
	temp->prec = list[0]->last;
	list[0]->last = temp;
	return (0);
}
