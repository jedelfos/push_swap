/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:49:12 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:18:50 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*s_malloc_util(size_t size, t_malloc *secure)
{
	t_malloc	*temp;

	temp = secure;
	while (temp->next != NULL)
		temp = temp->next;
	temp->adr = malloc(size);
	if (temp->adr == NULL)
		stop(2);
	temp->next = malloc(sizeof(secure));
	if (temp->next == NULL)
		stop(2);
	temp->next->adr = NULL;
	temp->next->next = NULL;
	return (temp->adr);
}

void	*s_malloc(int operation, size_t size)
{
	static t_malloc	*secure;
	t_malloc		*temp;

	if (operation == 1)
	{
		if (secure == NULL)
		{
			secure = malloc(sizeof(secure));
			if (secure == NULL)
				stop(2);
			secure->adr = NULL;
			secure->next = NULL;
		}
		return (s_malloc_util(size, secure));
	}
	while (secure != NULL)
	{
		temp = secure;
		secure = secure->next;
		if (temp->adr != NULL)
			free(temp->adr);
		free (temp);
	}
	return (NULL);
}

int	stop(int i)
{
	s_malloc (0, 0);
	if (i == 1)
		write (1, "Error\n", 6);
	if (i == 2)
		write (1, "Error malloc\n", 13);
	exit(0);
	return (0);
}
