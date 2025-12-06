CC = gcc
CFLAGS = -Wall -Wextra -g


main : main.o recursive.o
	$(CC) $(CFLAGS)  recursive.o main.o -o main
	@chmod +x main	

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

recursive.o : recursive.c
	$(CC) $(CFLAGS) -c recursive.c

clean : main.o 
	@rm main.o main recursive.o
