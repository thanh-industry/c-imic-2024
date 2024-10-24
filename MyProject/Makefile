CFLAGS += -g -Wall

EXEC = quanLySachThuVien


INC = -Iinc/
SRC = \
	main.c  \
	src/example.c\
	src/baiTap1.c\
	src/baiTap2.c\
	src/baiTap11.c\
	src/baiTapTamGiacPascal.c\
	src/baiTap8.c\
	src/studentsMarksSum.c\
	src/quanLySachThuVien.c

# Target cho abc
$(EXEC):
	$(CC) $(CFLAGS) $(SRC) $(INC) -o $@

clean:
	-rm -f $(EXEC)


