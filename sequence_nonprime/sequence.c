#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    for (int i = n - 1;i >= 1;i--)
        n *= i;
    return n;
}

int sequence(int *arr, int n, int i) {
    arr[i] =  factorial(n + 1) + 2 + i;
    
    if (i == n - 1) return 0;
    else
        return sequence(arr,n,i+1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./sequence <number of sequences>\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (n < 1) {
        printf("The number of sequences must be a natural number\n");
        return 1;
    }
    int *arr = (int *)malloc(n*sizeof(int));
    
    sequence(arr, n, 0);

    for (int i = 0;i <= n - 1;i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

