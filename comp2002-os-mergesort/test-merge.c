#include <stdio.h>
#include "mergesort.h"

/* define globals expected by mergesort.c */
int *A;
int *B;

/* prototype for the test function already implemented in mergesort.c */
void test_merge(void);

int main(void) {
    test_merge();
    return 0;
}