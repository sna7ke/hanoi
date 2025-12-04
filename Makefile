CC = gcc
CFLAGS = -Wall -Wextra -g


main : main.o 
	$(CC) $(CFLAGS)  main.o -o main
	@chmod +x main	

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

clean : main.o 
	@rm main.o main
