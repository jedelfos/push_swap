CC=gcc
CFLAGS=-Wall -Wextra -Werror -I ./includes/
NAME=push_swap
SRCS =	./srcs/calc_util.c \
		./srcs/calcul.c \
		./srcs/check.c \
		./srcs/first_operations.c \
		./srcs/last_operations.c \
		./srcs/low.c \
		./srcs/main.c \
		./srcs/midle_operations.c \
		./srcs/sec_malloc.c \
		./srcs/struct.c \
		./srcs/struct_utils.c

OBJS=$(SRCS:.c=.o)

INC=	./includes/push_swap.h \
		./includes/struc.h

RM=rm -f

%.c%.o:
	gcc $(CFLAGS) -c $< -o $@

all:		$(NAME)
$(OBJS):	$(INC)


$(NAME): 	$(INC) $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re