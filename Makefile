EXEC = rtoi
OBJ = $(EXEC).o

all: $(EXEC)

$(EXEC) : $(OBJ)
	clang++ -std=c++11 -o $@ $(OBJ)

%.o : %.cpp
	clang++ -std=c++11 -c $<

clean : tidy
	rm -rf $(EXEC)

tidy:
	rm -rf *.o

