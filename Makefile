EXEC = FizzBuzz
OBJ = $(EXEC).o

CC = clang++
CFLAGS = -std=c++20 -O2

all: $(EXEC)

$(EXEC): $(EXEC).cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(EXEC) *.dSYM

format:
	clang-format -style=file -i *.cpp *.c
	yapf -i *.py
