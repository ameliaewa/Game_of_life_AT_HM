GameOfLife: game.o Field.o main.o txtio.o pbmgen.o
	cc game.o Field.o main.o txtio.o pbmgen.o -o GameOfLife.out -Wall -pedantic
	mkdir out

game.o: game.c game.h
	cc -c game.c

Field.o: Field.c Field.h
	cc -c Field.c

main.o: main.c
	cc -c main.c

txtio.o: txtio.c txtio.h
	cc -c txtio.c

pbmgen.o: pbmgen.c pbmgen.h
	cc -c pbmgen.c

.PHONY:
clean:
	rm *.o *.out out/*.pbm