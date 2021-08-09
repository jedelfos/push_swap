/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:55:39 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/09 10:14:34 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "struc.h"

void	*s_malloc_util(size_t size, t_malloc *secure);
void	*s_malloc(int operation, size_t size);
int		sa(t_var **list);
int		sb(t_var **list);
int		ss(t_var **list);
int		ra(t_var **list);
int		rb(t_var **list);
int		rr(t_var **list);
int		rra(t_var **list);
int		rrb(t_var **list);
int		rrr(t_var **list);
int		pa(t_var **list);
int		pb(t_var **list);
int		stop(int i);
int		ft_atoi(char *str, int i);
int		skip_word(char *str, int i);
t_list	*ft_lstnew(int content, int *val);
void	ft_lstadd_back(t_var *list, int content, int *val);
void	ft_sort_int_tab(int *tab, int size);
t_var	**list_m_param(t_var **list, int argc, char **argv);
t_var	**create_list(int argc, char **argv);
int		min_max(t_var **list);
int		*calc_score_top(t_var **list, int *score);
int		*calc_score_bot(t_var **list, int *score);
int		calc_score(t_var **list);
int		positionement(t_var **list, int place);
int		positionement_final(t_var **list, int place);
int		cherche(t_var *list, int num);
int		is_sort(t_var **list);
int		check_argv(int argc, char **argv);
int		very_low_nb_utils(t_var **list);
int		very_low_nb(t_var **list);
int		low_nb(t_var **list);
int		low_check(t_var **list);
int		main(int argc, char **argv);

#endif