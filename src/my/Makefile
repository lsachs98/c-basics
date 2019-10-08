IDIR=../../include/
SRCS=$(wildcard *.c)
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
all: 
	$(CC) $(CFLAGS) -c *.c
	ar -rc libmy.a *.o
	ranlib libmy.a 
	mv libmy.a ../../lib
clean: 
	rm -f *.o
fclean: clean
	rm -f test
re: fclean all
test: ../../test/aids.c all
	$(CC) ../../test/aids.c $(CFLAGS) -L../../lib -lmy $(OBJS) -o test -lmy
