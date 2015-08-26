#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int low, int high) {
    int len = high - low;

    int temp, pivotValue;
    int i, c, wall = low, p = high - 1;

    if (len <= 1) {
        return;
    }

    // First we move elements around to make the pivot be in the middle of smaller and bigger values
    pivotValue = a[p];
    for (c = low; c < high; c++) {
        if (a[c] < pivotValue) {
            temp = a[c];
            a[c] = a[wall];
            a[wall] = temp;
            wall++;
        }
    }
    // Move pivot to wall
    a[p] = a[wall];
    a[wall] = pivotValue;

    // Sort the left and right sides of the array
    quickSort(a, low, wall);
    quickSort(a, wall + 1, high);

    return;
}

int main() {
    int a[] = {6, 1, 9, 88, 12, -10, 7, 3, 5};
    int l = sizeof(a) / sizeof(int);
    int i;
    
    quickSort(a, 0, l);

    for (i = 0; i < l; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");

    return 0;
}