all: 	client.c
	gcc client.c -o client -Wall -Werror --pedantic -I../../include -L../../lib -lmy -llist -g -std=c99
	server.c
	gcc server.c -o server -Wall -Werror --pedantic -I../../include -L../../lib -lmy -llist -g -std=c99

clean:
	rm -f *.o

fclean: clean
	rm -f client
	rm -f server	

re: fclean all



