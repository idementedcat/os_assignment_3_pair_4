CC = gcc
CFLAGS = -Wall -Wpointer-arith -Wstrict-prototypes -std=gnu89 -fPIC -MMD -MP -g
LDFLAGS = -lpthread

all: test-mergesort

test-mergesort: test-mergesort.o mergesort.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# small test executable that calls test_merge()
test-merge: mergesort.o test-merge.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# generic rule for compiling .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	/bin/rm -f *.o *.d test-mergesort test-merge
