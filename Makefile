CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O3 -Wall -w		# compilation flags: -g for debugging. Change to -O or
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = Reversi		# target executable (output)
SRC = main.cpp grid.cpp game_display.cpp ai.cpp       # .c or .cpp source files.
OBJ = $(SRC:.cpp=.o) 	# object files for the target. Add more to this and next lines if there are more than one source files.

all : $(PROG)

$(PROG): $(OBJ) 
		$(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

.cpp.o:
		$(CC) -c $(CFLAGS) $< -o $@

clean:
	/bin/rm -f *.o $(PROG)

