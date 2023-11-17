SRCS = ft_printf.c ft_file1.c ft_file2.c

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS_OBJ = $(SRCS:.c=.o)

%.o:%.c
	cc $(CFLAGS) -c $^ -o $@

all: $(NAME) ft_printf.h

$(NAME): $(SRCS_OBJ)
	ar -rc $(NAME) $(SRCS_OBJ)
clean : 
	rm -rf $(SRCS_OBJ)
fclean :
	rm -rf $(SRCS_OBJ) $(NAME)
