/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:53:33 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:10 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*calc_score_top(t_var **list, int *score)
{
	int		i;
	t_list	*temp;

	i = 1;
	temp = list[0]->first;
	while ((i < ((list[0]->n_val / 2) + 1)) && temp != NULL)
	{
		if (((((list[0]->max - temp->val) * 2) + i) < score[1])
			|| (score[1] == 0))
		{
			score[0] = i;
			score[1] = i + ((list[0]->max - temp->val) * 2);
		}
		if ((((temp->val - list[0]->min) * 2) + i) < score[1])
		{
			score[0] = i;
			score[1] = i + ((temp->val - list[0]->min) * 2);
		}
		temp = temp->next;
		i++;
	}
	return (score);
}

int	*calc_score_bot(t_var **list, int *score)
{
	int		i;
	t_list	*temp;

	i = 2;
	temp = list[0]->last;
	while ((i < ((list[0]->n_val / 2) + 1)) && temp != NULL)
	{
		if ((((((list[0]->max) - temp->val) * 2) + i) < score[1])
			|| (score[1] == 0))
		{
			score[0] = i * -1;
			score[1] = i + ((list[0]->max - temp->val) * 2);
		}
		if ((((temp->val - list[0]->min) * 2) + i) < score[1])
		{
			score[0] = i * -1;
			score[1] = i + ((temp->val - list[0]->min) * 2);
		}
		temp = temp->prec;
		i++;
	}
	return (score);
}

int	calc_score(t_var **list)
{
	int		*score;
	t_list	*temp;

	score = s_malloc(1, sizeof(int) * 2);
	score[0] = 0;
	score[1] = 0;
	score = calc_score_top(list, score);
	score = calc_score_bot(list, score);
	return (score[0]);
}

int	positionement(t_var **list, int place)
{
	while (place < -1)
	{
		rra(list);
		place ++;
	}
	while (place > 1)
	{
		ra(list);
		place --;
	}
	pb(list);
	if (list[1]->first->val > (((list[0]->max - list[0]->min) / 2)
			+ list[0]->min) && list[1]->first->next)
		rb(list);
	return (0);
}

int	positionement_final(t_var **list, int place)
{
	while (place < 0)
	{
		rrb(list);
		place ++;
	}
	while (place > 1)
	{
		rb(list);
		place --;
	}
	pa(list);
	return (0);
}
