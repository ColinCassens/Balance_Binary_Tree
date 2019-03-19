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

clean:
	rm -f *.o valgrind.log pa4
	clear
