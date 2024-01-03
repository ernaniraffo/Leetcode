EXEC = addBinary
OBJ = $(EXEC).o

CC = clang
CFLAGS = -std=c11 -O2

all: $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean : tidy
	rm -rf $(EXEC)

tidy:
	rm -rf *.o

