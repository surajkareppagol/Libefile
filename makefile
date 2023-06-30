CC = gcc
SRCS = efile.c main.c
INCS = efile.h

main: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o main

.PHONY: run
run:
	@./main

.PHONY: clean
clean:
	@rm main -rf