# Name the project executable
PROJ_LABEL = BWT

# Main code source
CSRC = main.c

# Files of lib
LIB = $(wildcard lib/*.h)
# Files of src
SRC = $(wildcard src/*.c)

# Object Files
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC) )

# Compiler
CC = gcc

# Compile Flags
CFLAGS = 	-Wall\
 					-Werror
					
VALGRIND_FLAGS = 	-g\
									-O0

all: ${PROJ_LABEL}

${PROJ_LABEL}: ${OBJ} ${LIB} ${SRC} ${CSRC}
	${CC} ${CFLAGS} ${CSRC} ${OBJ} -o $@

obj/%.o: src/%.c lib/%.h
	${CC} $< -c -o $@

clean:
	rm -rf obj/*.o ${PROJ_LABEL}

teste_obj:
	touch ${SRC}
	touch ${OBJ}