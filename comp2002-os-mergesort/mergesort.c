/**
 * This file implements parallel mergesort.
 */

#include <stdio.h>
#include <string.h> /* for memcpy */
#include <stdlib.h> /* for malloc */
#include "mergesort.h"

/* this function will be called by mergesort() and also by parallel_mergesort(). */
void merge(int leftstart, int leftend, int rightstart, int rightend){
    // merge the two sorted subarrays A[leftstart..leftend] and A[rightstart..rightend]
    int i = leftstart;
    int j = rightstart;
    int k = leftstart;

    while (i <= leftend && j <= rightend) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // copy any remaining elements from either subarray
    while (i <= leftend) {
        B[k++] = A[i++];
    }
    while (j <= rightend) {
        B[k++] = A[j++];
    }

    // copy the merged elements back into the original array
    memcpy(A + leftstart, B + leftstart, (rightend - leftstart + 1) * sizeof(int));
}

/* Test function for merge */
void test_merge(void) {
    int i; // declare loop var at top for C89/gnu89 compatibility

    // Create a small test array with two sorted halves
    A = (int*)malloc(10 * sizeof(int));
    B = (int*)malloc(10 * sizeof(int));
    
    // First sorted half: 1,3,5,7,9
    A[0] = 1; A[1] = 3; A[2] = 5; A[3] = 7; A[4] = 9;
    // Second sorted half: 2,4,6,8,10
    A[5] = 2; A[6] = 4; A[7] = 6; A[8] = 8; A[9] = 10;
    
    printf("Before merge:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // Call merge on the two halves
    merge(0, 4, 5, 9);
    
    printf("After merge:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    // Verify if sorted
    int sorted = 1;
    for(i = 0; i < 9; i++) {
        if(A[i] > A[i+1]) {
            sorted = 0;
            break;
        }
    }
    printf("Array is %s\n", sorted ? "correctly sorted" : "not sorted");
    
    free(A);
    free(B);
}

/* this function will be called by parallel_mergesort() as its base case. */
void my_mergesort(int left, int right){
    /* left as a placeholder; do not call test_merge() here when running the real test */
}

/* this function will be called by the testing program. */
void * parallel_mergesort(void *arg){
        return NULL;
}

/* we build the argument for the parallel_mergesort function. */
struct argument * buildArgs(int left, int right, int level){
        return NULL;
}

