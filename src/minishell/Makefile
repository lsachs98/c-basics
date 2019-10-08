IDIR=../../include/
CC=gcc
CFLAGS = -I$(IDIR) -Wall -Werror --pedantic
LIBFLAGS = -L../../lib/ -lmy

all:
	$(CC) minishell.c $(CFLAGS) $(LIBFLAGS) -o minishell

clean:
	rm -f *.o

fclean: clean
	rm -f minishell

re: fclean all
