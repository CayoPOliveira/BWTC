# Name the project executable
PROJ_LABEL = BWT

# Main code source
CSRC = main.c

# Files of lib
LIB = lib/*.h
# Files of src
SRC = src/*.c

# Object Files
OBJ = $(SRC: src/%.c = obj/%.o)

# Compiler
CC = gcc

# Compile Flags
CFLAGS = 	-Wall\
 					-Werror
						
VALGRIND_FLAGS = 	-g\
									-O0

all: ${PROJ_LABEL}

${PROJ_LABEL}: ${OBJ} ${LIB} ${SRC} ${CSRC}
	${CC} ${CFLAGS} ${CSRC} $< -o $@

obj/%.o: src/%.c lib/%.h
	${CC} $< -o $@

clean:
	rm -rf obj/*.o 