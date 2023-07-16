CC = gcc
SRCS = util.c efile.c main.c
INCS = util.h efile.h

main: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o main

.PHONY: debug
debug:
	@$(CC) -o0 $(SRCS) -o debug.out -g
	@gdb debug.out

.PHONY: run
run:
	@clear && ./main

.PHONY: clean
clean:
	@rm main -rf
