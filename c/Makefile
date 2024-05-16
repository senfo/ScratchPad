CC=gcc
CFLAGS = -Wall -Werror -O2 -DDEBUG
CXXFLAGS += -I/usr/local/include
LDFLAGS += -L/usr/local/lib

3and5: 3and5.o
	$(CC) -o 3and5 3and5.o

depth: depth.o
	$(CC) -o depth depth.o

dynamiclinkedlist: dynamiclinkedlist.o
	$(CC) -o dynamiclinkedlist dynamiclinkedlist.o

fibonacci: fibonacci.o
	$(CC) -o fibonacci fibonacci.o

fizz_buzz: fizz_buzz.o
	$(CC) -o fizz_buzz fizz_buzz.o

highest: highest.o
	$(CC) -o highest highest.o

json: json.o cJSON.o
	$(CC) -o json json.o cJSON.o
	
linkedlist: linkedlist.o
	$(CC) -o linkedlist linkedlist.o

linktest: linktest.o
	$(CC) -o linktest linktest.o

palindrome: palindrome.o
	$(CC) -o palindrome palindrome.o

prime: prime.o
	$(CC) -o prime prime.o

probability: probability.o
	$(CC) -o probability probability.o

smallest: smallest.o
	$(CC) -o smallest smallest.o

watcher: watcher.o
	 $(CC) -o watcher watcher.o
	
all: 3and5 depth dynamiclinkedlist fibonacci fizz_buzz highest json linkedlist linktest palindrome prime probability smallest watcher

clean:
	@rm *.o 3and5 depth dynamiclinkedlist fibonacci fizz_buzz highest json linkedlist linktest palindrome prime probability smallest 2> /dev/null || true
