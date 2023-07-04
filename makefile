CC = gcc
SRCS = efile.c main.c
INCS = efile.h

main: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o main

.PHONY: debug
debug:
	@$(CC) -o0 $(SRCS) -o debug.out -g
	@gdb debug.out

.PHONY: run
run:
	@./main

.PHONY: clean
clean:
	@rm main -rf
