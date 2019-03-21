GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
VAL = valgrind --tool=memcheck --log-file=valgrind.log --leak-check=full --show-reachable=yes --verbose  --track-origins=yes
TESTFLAGS = -DTEST_MAIN
SRCS = main.c helper.c #UPDATE WITH MORE FILES
OBJS = $(SRCS:%.c=%.o)

PA4: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o pa4

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

VAL: pa4
	$(VAL) ./pa4

test1: pa4
	./pa4 -b examples/ops0.b tree0.txt
	diff tree0.txt examples/tree0.txt

test2: pa4
	./pa4 -b examples/ops1.b tree1.txt
	diff tree1.txt examples/tree1.txt

test3: pa4
	./pa4 -b examples/ops2.b tree2.txt
	diff tree2.txt examples/tree2.txt

clean:
	rm -f *.o *.txt *.b valgrind.log pa4 
	clear
