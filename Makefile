CC = gcc
CFLAGS = -Wall -Wextra -g


main : main.o recursive.o iterative.o
	$(CC) $(CFLAGS)  iterative.o recursive.o main.o -o main
	@chmod +x main	

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

recursive.o : recursive.c
	$(CC) $(CFLAGS) -c recursive.c
iterative.o : iterative.c
	$(CC) $(CFLAGS) -c iterative.c


clean : main.o 
	@rm main.o main recursive.o
