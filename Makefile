CFLAGS += -g -Wall

EXEC = abc

INC = -Iinc/
SRC = \
	main.c  \

	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)
