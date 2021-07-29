/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:05:55 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 17:10:07 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H
# include "push_swap.h"

typedef struct var
{
	int				coup;
	int				min;
	int				max;
	int				n_val;
	struct s_list	*first;
	struct s_list	*last;
}					t_var;

typedef struct s_list
{
	int				content;
	int				val;
	struct s_list	*next;
	struct s_list	*prec;
}					t_list;

typedef struct s_malloc
{
	void			*adr;
	struct s_malloc	*next;
}					t_malloc;

#endif