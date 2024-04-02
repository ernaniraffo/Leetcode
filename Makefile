EXEC = FizzBuzz
OBJ = $(EXEC).o

CC = clang++
CFLAGS = -std=c++20 -O2

all: $(EXEC)

$(EXEC) : $(EXEC).cpp
	$(CC) $(CFLAGS) $^ -o $@

clean : tidy
	rm -rf $(EXEC)

tidy:
	rm -rf *.o

format:
	clang-format -style=file -i *.cpp *.c
	yapf -i *.py
