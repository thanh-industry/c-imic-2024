CFLAGS += -g -Wall

EXEC = run

INC = -Iinc/
SRC = \
	main.c  \
	src/BAI_1.c \
	src/BAI_2.c \
	src/BAI_4.c \
	src/BAI_5.c \
	src/BAI_6.c \


	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)