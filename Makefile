CFLAGS += -g -Wall

EXEC = run

INC = -Iinc/
SRC = \
	main.c  \
	src/BAI_5.c


	
#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)