CFLAGS =-std=c11 -Wall -Wextra -Wpedantic -o2

grep: grep.o lineread.o
grep.o: grep.c lineread.h
lineread.o: lineread.c lineread.h

clean:
	rm -f grep *.o
