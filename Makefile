EXEC = multiplyStrings
OBJ = $(EXEC).o

CC = clang++
CFLAGS = -std=c++17 -O2

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean : tidy
	rm -rf $(EXEC)

tidy:
	rm -rf *.o

