#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"

/* define globals expected by mergesort.c */
int *A;
int *B;

#define RANGE 1000000

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

/* refined test: build a random array, sort each half, then call merge */
void test_merge(void) {
    int n = 100;
    int i;
    unsigned int seed = (unsigned int)time(NULL);

    A = (int*)malloc(n * sizeof(int));
    B = (int*)malloc(n * sizeof(int));
    if (A == NULL || B == NULL) {
        fprintf(stderr, "malloc failed in test_merge\n");
        exit(EXIT_FAILURE);
    }

    /* generate random array like test-mergesort.c */
    srandom((unsigned int)seed);
    for (i = 0; i < n; i++) {
        A[i] = (int)(random() % RANGE);
    }

    /* sort each half so merge() has two sorted runs to merge */
    qsort(A, n/2, sizeof(int), cmp_int);
    qsort(A + n/2, n - n/2, sizeof(int), cmp_int);

    printf("Seed: %u\n", seed);
    printf("Array A (before merge; two sorted halves):");
    for (i = 0; i < n; i++) printf(" %d", A[i]);
    printf("\n");

    merge(0, n/2 - 1, n/2, n - 1);

    printf("Array A (after merge):");
    for (i = 0; i < n; i++) printf(" %d", A[i]);
    printf("\n");

    {
        int sorted = 1;
        for (i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) { sorted = 0; break; }
        }
        printf("Array is %s\n", sorted ? "correctly sorted" : "not sorted");
    }

    free(A);
    free(B);
}

int main(void) {
    test_merge();
    return 0;
}