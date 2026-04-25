help:
	@echo Available targets:
	@echo maker: builds and runs maker.c
	@echo strinspect: builds and runs strinspect.c with sample string Hello

.PHONY: maker strinspect

maker: maker.c
	gcc -g -O0 -o maker ./maker.c && ./maker

strinspect: strinspect.c
	gcc -g -O0 -o strinspect ./strinspect.c  && ./strinspect Hello
