CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = fractol.c parssing.c fractal_init.c julia.c
OBJS = $(SRCS:.c=.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)

$(OBJS): fractol.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
