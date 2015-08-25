#include <stdio.h>

int* iSort(int a[], int l) {
    int i, c; // Indexes
    int current; // Values
    for (i = 1; i < l; i++) {
        c = i - 1;
        current = a[i];
        while (a[c] > current && c >= 0) {
            a[c + 1] = a[c];
            c--;
        }
        a[c + 1] = current;
    }
    return a;
}

int main() {
    int a[] = {3,2,1,5,0};
    int i, l = 5;
    int *b;
    b = iSort(a, l);

    for (i = 0; i < l; i++) {
        printf("Value: %d\n", b[i]);
    }
    return 0;
}