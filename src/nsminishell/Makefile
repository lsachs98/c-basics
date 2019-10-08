IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
LIBFLAGS = -L../../lib/ -lmy -lncurses -llist

all:
	$(CC) nsminishell.c $(CFLAGS) $(LIBFLAGS) -o nsminishell

clean:
	rm -f *.o

fclean: clean
	rm -f nsminishell

re: fclean all
