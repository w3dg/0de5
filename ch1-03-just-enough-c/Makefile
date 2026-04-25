help:
	@echo Available targets:
	@echo fizzbuzz: builds and runs fizzbuzz.c
	@echo fizzbuzz2: builds and runs fizzbuzz2.c
	@echo prime: builds and runs prime.c

.PHONY: fizzbuzz fizzbuzz2 prime

fizzbuzz: fizzbuzz.c
	gcc -g -O0 -Wall -Werror -o fizzbuzz ./fizzbuzz.c && ./fizzbuzz 15

fizzbuzz2: fizzbuzz2.c
	gcc -g -O0 -Wall -Werror -o fizzbuzz2 ./fizzbuzz2.c && ./fizzbuzz2 15

prime: prime.c
	gcc -g -O0 -Wall -Werror -o prime ./prime.c && ./prime 1000 && ./prime 10000 && ./prime 100000
