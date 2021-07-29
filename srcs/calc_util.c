/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:50:43 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:08:01 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	calc(int i, const char *str, int sign)
{
	long	result;
	int		j;

	result = 0;
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		if (result > 2147483648 && sign == 1)
			return (0);
		if (result > 2147483647 && sign == 0)
			return (-1);
		i++;
	}
	if (j == i)
		stop(1);
	return (result);
}

int	ft_atoi(char *str, int i)
{
	int	result;
	int	sign;

	sign = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
		if (str[i] == '+' || str[i] == '-'
			|| (!(str[i] >= '0' && str[i] <= '9')))
			stop(1);
	}
	result = calc(i, str, sign);
	if (sign % 2 == 0)
		return (result);
	return (result * -1);
}

int	skip_word(char *str, int i)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	if ((!(str[i] == '+' || str[i] == '-' || (str[i] >= '0'
					&& str[i] <= '9'))) || str[i] == '\0')
		return (-1);
	return (i);
}
