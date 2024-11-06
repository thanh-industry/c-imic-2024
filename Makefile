# Complier and flags define
CC = gcc
CXX = g++
CFLAGS += -g -Wall
CXXFLAGS += -g -Wall

EXEC = run


# Source and includes files
INC = -Iinc/

SRC_C = \
	src/error_handling.c \
	src/BAI_1.c \
	src/BAI_2.c \
	src/BAI_4.c \
	src/BAI_5.c \
	src/BAI_6.c \
	src/BAI_7.c \
	src/BAI_8.c \
	src/BAI_9.c \

SRC_CPP = \
	main.cpp  \
	src/BAI_10.cpp \


# Method for converting source files to object files
OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)
OBJS = $(OBJ_C) $(OBJ_CPP)


# Pattern rule for compiling C source files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Pattern rule for compiling C++ source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	

# build target
$(EXEC):  $(OBJ_C) $(OBJ_CPP)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(OBJ_C) $(OBJ_CPP) $(INC) -o $@

# SHELL = cmd.exe
# define OS for cleaning method
ifeq ($(OS),Windows_NT)
	EXEC_EXT = .exe
	OBJ_CLEAN_CMD = del /F /Q $(subst /,\,$(OBJS))
	EXEC_CLEAN_CMD = del /F /Q $(EXEC)$(EXEC_EXT)
else
	EXEC_EXT =
	OBJ_CLEAN_CMD = rm -f $(OBJS)
	EXEC_CLEAN_CMD = rm -f $(EXEC)
endif


# clean file
clean:
	$(EXEC_CLEAN_CMD)
	$(OBJ_CLEAN_CMD)

# clean only object files
oclean:
	$(OBJ_CLEAN_CMD)