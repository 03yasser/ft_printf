SRCS = ft_string.c

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS_OBJ = $(SRCS:.c=.o)

%.o:%.c
	cc $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	ar -rc $(NAME) $(SRCS_OBJ)
clean : 
	rm -rf $(SRCS_OBJ)
fclean :
	rm -rf $(SRCS_OBJ) $(NAME)
