#.SILENT:

NAME= libft.a

SRCS=	ft_memset.c			ft_bzero.c			ft_memcpy.c		\
		ft_memccpy.c	 	ft_memmove.c 		ft_memchr.c		\
		ft_memcmp.c 		ft_strlen.c 		ft_strdup.c		\
		ft_strchr.c			ft_strclen.c		ft_swap.c		\
		ft_strrchr.c 		ft_strstr.c 		ft_strcmp.c		\
		ft_atoi.c 			ft_isalpha.c 		ft_isdigit.c	\
		ft_isalnum.c	 	ft_isascii.c 		ft_isprint.c	\
		ft_toupper.c 		ft_tolower.c 		ft_strmapi.c	\
		ft_strjoin.c 		ft_strtrim.c 		ft_split.c		\
		ft_itoa.c 			ft_putchar.c 		ft_putstr.c		\
		ft_putnbr.c			ft_calloc.c			ft_substr.c		\
		ft_isspace.c		ft_count_word.c		get_next_line.c	\
		ft_realloc.c		ft_lputstr.c


OBJS_S= $(SRCS:%.c=%.o)

CC= gcc

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_S)
	ar -rcs $(NAME) $(OBJS_S)

clean:
	rm -f $(OBJS_S)

fclean: clean
	rm -f $(NAME)

re: fclean all
