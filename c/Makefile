CC=gcc
CFLAGS = -Wall -Werror -O2 -DDEBUG
CXXFLAGS += -I/usr/local/include
LDFLAGS += -L/usr/local/lib

3and5: 3and5.o
	$(CC) -o 3and5 3and5.o

depth: depth.o
	$(CC) -o depth depth.o

fibonacci: fibonacci.o
	$(CC) -o fibonacci fibonacci.o

fizz_buzz: fizz_buzz.o
	$(CC) -o fizz_buzz fizz_buzz.o

highest: highest.o
	$(CC) -o highest highest.o

json: json.o cJSON.o
	$(CC) -o json json.o cJSON.o

palindrome: palindrome.o
	$(CC) -o palindrome palindrome.o

prime: prime.o
	$(CC) -o prime prime.o

probability: probability.o
	$(CC) -o probability probability.o

smallest: smallest.o
	$(CC) -o smallest smallest.o
	
all: 3and5 fibonacci fizz_buzz highest json palindrome prime probability smallest # Intentionally left off "depth" because it's borked

clean:
	@rm *.o 3and5 depth fibonacci fizz_buzz highest json palindrome prime probability smallest 2> /dev/null || true
