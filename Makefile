# Name the project executable
PROJ_LABEL = BWT

# Main code source
C_SRC = src/main.c

# Files of lib
LIB = lib/*.h
# Files of src
SRC = src/*.c

# Object Files
OBJ = $(SRC: .c = .o)

# Compiler
CC = gcc

# Compile Flags
CC_FLAGS = 	-Wall\
 						-Werror
						
VALGRIND_FLAGS = 	-g\
									-O0

