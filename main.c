/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:19:07 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/29 16:19:11 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

int	stop(int i);

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

t_var	**list_m_param(t_var **list, int argc, char **argv)
{
	int	y;
	int	*val;

	y = 0;
	val = s_malloc(1, sizeof(int) * argc);
	while (y < argc - 1)
	{
		val[y] = ft_atoi(argv[y + 1], 0);
		y++;
	}
	ft_sort_int_tab(val, argc - 1);
	y = 1;
	while (y < argc)
	{
		ft_lstadd_back(list[0], ft_atoi(argv[y], 0), val);
		y++;
	}
	return (list);
}

t_var	**list_s_param_utils(t_var **list, char **argv, int *val, int i)
{
	int	y;
	int	u;

	u = 0;
	y = 0;
	while (u != -1)
	{
		val[y] = ft_atoi(argv[1], u);
		u = skip_word(argv[1], u);
		y++;
	}
	ft_sort_int_tab(val, i - 1);
	u = 0;
	while (u != -1)
	{
		ft_lstadd_back(list[0], ft_atoi(argv[1], u), val);
		u = skip_word(argv[1], u);
	}
	return (list);
}

t_var	**list_s_param(t_var **list, char **argv)
{
	int	y;
	int	i;
	int	*val;

	y = 0;
	i = 1;
	while (y != -1)
	{
		y = skip_word(argv[1], y);
		i++;
	}
	val = s_malloc(1, sizeof(int) * i);
	list = list_s_param_utils(list, argv, val, i);
	return (list);
}

t_var	**create_list(int argc, char **argv)
{
	t_var	**list;
	int		y;

	y = 0;
	list = s_malloc(1, sizeof(t_var *) * 2);
	list[0] = s_malloc(1, sizeof(t_var));
	list[0]->first = NULL;
	list[0]->last = NULL;
	list[1] = s_malloc(1, sizeof(t_var));
	list[1]->first = NULL;
	list[1]->last = NULL;
	if (argc > 2)
		list_m_param(list, argc, argv);
	else
		list_s_param(list, argv);
	return (list);
}

int	min_max(t_var **list)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (i < 2)
	{
		list[i]->n_val = 0;
		temp = list[i]->first;
		list[i]->max = -1;
		list[i]->min = -1;
		while (temp != NULL)
		{
			if (temp->val > list[i]->max)
				list[i]->max = temp->val;
			if ((temp->val < list[i]->min) || (list[i]->min == -1))
				list[i]->min = temp->val;
			list[i]->n_val++;
			list[i]->last = temp;
			temp = temp->next;
		}
		i++;
	}
	return (0);
}

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

int	cherche(t_var *list, int num)
{
	t_list	*temp;
	int		i;
	int		y;

	temp = list->first;
	i = 1;
	y = 1;
	while (temp->next && temp->val != num)
	{
		i++;
		temp = temp->next;
	}
	temp = list->last;
	while (temp->prec && temp->val != num)
	{
		y ++;
		temp = temp->prec;
	}
	if (i <= y)
		return (i);
	return (y * -1);
}

int	is_sort(t_var **list)
{
	t_list	*temp;

	temp = list[0]->first;
	while (temp->next != NULL)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	int	i;
	int	y;

	if (argc == 1)
		stop(1);
	i = 1;
	y = 0;
	while (argc > i)
	{
		while (argv[i][y] != '\0')
		{
			if (!(((argv[i][y] >= '0' && argv[i][y] <= '9')
				|| (argv[i][y] == '\t' || argv[i][y] == '\n'
				|| argv[i][y] == '\v' || argv[i][y] == '\f'
				|| argv[i][y] == '\r' || argv[i][y] == ' '
				|| argv[i][y] == '+' || argv[i][y] == '-'))))
				stop(1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_var	**list;
	int		place;

	check_argv(argc, argv);
	list = (t_var **)create_list(argc, argv);
	if (is_sort(list))
		stop(0);
	low_check(list);
	while (list[0]->first->next != NULL)
	{
		min_max(list);
		place = calc_score(list);
		positionement(list, place);
	}
	pb(list);
	min_max(list);
	while (list[1]->n_val > 1)
	{
		min_max(list);
		place = cherche(list[1], list[1]->max);
		positionement_final(list, place);
	}
	s_malloc (0, 0);
	return (0);
}
