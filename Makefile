NAME 	= libftprintf.a

LIBFT = libft
SRCS	= ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_d.c ft_printf_u.c ft_printf_x.c ft_printf_p.c util.c util2.c
SRCS_B	=

OBJS	= $(patsubst %.c,%.o,$(SRCS))
OBJS_B  = $(patsubst %.c,%.o,$(SRCS_B))

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

INCLUDES = -I./includes

HEADER = includes/ft_printf.h

all:	$(NAME)

%.o : %.c	$(HEADER) libft/libft.h
	gcc $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME):	$(OBJS)
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)
	cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJS)

bonus:
	@make OBJS="$(OBJS_B)" all

clean:
	@make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
	$(RM) $(LIBFT)/libft.a
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
