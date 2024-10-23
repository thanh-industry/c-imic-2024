CFLAGS += -g -Wall

EXEC = run

INC = -Iinc/
SRC = \
	main.c  \
	src/error_handling.c \
	src/BAI_1.c \
	src/BAI_2.c \
	src/BAI_4.c \
	src/BAI_5.c \
	src/BAI_6.c \
	src/BAI_7.c \
	src/BAI_8.c \
	src/BAI_9.c \

ifeq ($(OS),Windows_NT)
	SHELL = cmd.exe
    RM = del /F /Q
	EXEC_EXT = .exe
else
    RM = rm -f
	EXEC_EXT =
endif
	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-$(SHELL) /C $(RM)  $(EXEC)$(EXEC_EXT)