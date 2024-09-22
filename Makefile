CFLAGS += -g -Wall

EXEC = abc

INC = -Iinc/
SRC = \
	main.c  \
	src/example.c 

	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)