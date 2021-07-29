/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:51:04 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:09:16 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int content, int *val)
{
	t_list	*result;
	int		i;

	i = 0;
	result = (t_list *)s_malloc(1, sizeof(t_list));
	result->next = NULL;
	result->prec = NULL;
	result->content = content;
	while (val[i] != content)
		i++;
	result->val = i + 1;
	return (result);
}

void	ft_lstadd_back(t_var *list, int content, int *val)
{
	t_list	*new;

	new = ft_lstnew(content, val);
	if (list->last == NULL)
		list->first = new;
	else
		list->last->next = new;
	new->prec = list->last;
	list->last = new;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1] && (i < (size - 1)))
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
		if (i > 0 && tab[i - 1] == tab[i])
			stop(1);
	}
}
