CC = gcc
CFLAGS += -g -Wall

EXEC = run

INC = -Iinc/
SRC = \
	main.c  \
	src/BaiTap1_1.c	\
	src/BaiTap1_2.c	\
	src/BaiTap1_3.c	\
	src/BaiTap1_4.c \
	src/BaiTap2.c \
	src/BaiTap3_1.c \
	src/BaiTap3_2.c \
	src/BaiTap4.c 

#target
$(EXEC):  
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@


clean:
	-rm -f  $(EXEC)