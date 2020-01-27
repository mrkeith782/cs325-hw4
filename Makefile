CC = g++

knapsack: knapsack.o
	$(CC) knapsack.o -o knapsack.exe $(CFLAGS)

clean:
	rm -f a.out knapsack.o knapsack.exe 

.PHONY: clean