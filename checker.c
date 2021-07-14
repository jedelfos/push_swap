#include "stdlib.h"
#include <stdio.h>

int 	intlent(int *i)
{
	int len = 0;
	while(i[len] != -1)
	{
		len ++;
	}
	return len;
}

int		affichage(int *a, int *b)
{
	int i = 0;
	
	printf("\n\n\nc : ");
	int lena = intlent(a);
	int lenb = intlent(b);

	while(lena >= i || lenb >= i)
	{
		printf("%3i", i);
		i++;
		if (lena >= i || lenb >= i)
			printf(" , ");
	}
	i = 0;
	printf("\n\n\na : ");

	while(lena >= i)
	{
		printf("%3i", a[i]);
		i++;
		if (lena >= i)
			printf(" , ");
	}

	i = 0;
	printf("\n\n\nb : ");
	while(lenb >= i)
	{
		printf("%3i", b[i]);
		i++;
		if (lenb >= i)
			printf(" , ");
	}
		printf("\n\n\n");
	return 0;
}


int		sa(int *a, int *b)
{
	int tmp;
	if (a[0] && a[1])
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	return 0;
}

int		sb(int *a, int *b)
{
	int tmp;
	if (b[0] && b[1])
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
	return 0;
}

int		ss(int *a, int *b)
{
	sa(a, b);
	sb(a, b);
	return 0;
}

int		pa(int *a, int *b)
{
	int i = 0;
	if(b[0] == -1)
		return 0;
	while(a[i] != -1)
		i++;
	a[i + 1] = -1; 
	while(i - 1 >= 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while(b[i] != -1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = b[i + 1];
	return 0;
}

int		pb(int *a, int *b)
{
	int i = 0;
	if(a[0] == -1)
		return 0;
	while(b[i] != -1)
		i++;
	b[i + 1] = -1; 
	while(i - 1 >= 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while(a[i] != -1)
	{ 
		a[i] = a[i + 1];
		i++;
	}
		a[i] = a[i + 1];
	return 0;
}



int		ra(int *a, int *b)
{
	int i;
	int tmp;
	if (a[0] == -1 || a[1] == -1)
		return 0;
	tmp = a[0];
	i = 0;
	while (a[i] != -1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = tmp;
	a[i] = -1;
	return 0;
}


int		rb(int *a, int *b)
{
	int i;
	int tmp;
	if (b[0] == -1 || b[1] == -1)
		return 0;
	tmp = b[0];
	i = 0;
	while (b[i] != -1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = tmp;
	b[i] = -1;
	return 0;
}

int		rr(int *a, int *b)
{
	ra(a,b);
	rb(a,b);
	return 0;
}


int		rra(int *a, int *b)
{
	int i;
	int tmp;
	if (a[0] == -1 || a[1] == -1)
		return 0;
	i = intlent(a);
	tmp = a[i - 1];
	a[i] = -1;
	i--;		
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
	return 0;
}

int		rrb(int *a, int *b)
{
	int i;
	int tmp;
	if (b[0] == -1 || b[1] == -1)
		return 0;
	i = intlent(b);
	tmp = b[i - 1];
	b[i] = -1;
	i--;		
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
	return 0;
}

int		rrr(int *a, int *b)
{
	rra(a,b);
	rrb(a,b);
	return 0;
}

char 	*cheker(int *a, int *b)
{

	return 0;
}

int     main()
{
	int *a;
	int *b;

	a = malloc(sizeof(int) * 150);
	b = malloc(sizeof(int) * 150);

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	a[5] = 6;
	a[6] = 7;
	a[7] = 8;
	a[8] = 9;
	a[9] = 11;
	a[10] = -1;

	b[0] = 10;
	b[1] = 20;
	b[2] = 30;
	b[3] = 40;
	b[4] = 50;
	b[5] = 60;
	b[6] = 70;
	b[7] = 80;
	b[8] = 90;
	b[9] = 100;
	b[10] = -1;


	
	affichage(a,b);
	rra(a,b);
	affichage(a,b);




	return(0);
	
}



/*

sa :swap a- swap the first 2 elements at the top of stacka. Do nothing if thereis only one or no elements).
sb :swap b- swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements).
ss :saandsbat the same time.
pa :push a- take the first element at the top ofband put it at the top ofa. Donothing ifbis empty.
pb :push b- take the first element at the top ofaand put it at the top ofb. Donothing ifais empty.
ra :rotate a- shift up all elements of stackaby 1. The first element becomesthe last one.
rb :rotate b- shift up all elements of stackbby 1. The first element becomesthe last one.
rr :raandrbat the same time.
rra :reverse rotate a- shift down all elements of stackaby 1. The last elementbecomes the first one.7 Push_swapBecause Swap_push isn’t as natural
rrb :reverse rotate b- shift down all elements of stackbby 1. The last elementbecomes the first one.
rrr :rraandrrbat the same time
*/