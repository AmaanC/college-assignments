#include <stdio.h>
#include <stdlib.h>

void print_arr(int a[], int l) {
    int i;
    for (i = 0; i < l; i++) {
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int* mergeSort(int a[], int start, int end) {
    int len = end - start;
    int mid = start + len / 2;
    int leftLen = (mid - start);
    int rightLen = (end - mid);
    int *result = malloc(len);
    int *left;
    int *right;

    int i, j, c;
    int max = -999999;
    if (len <= 1) {
        printf("Only 1 elem: %d\n", a[start]);
        result[0] = a[start];
        return result;
    }

    left = mergeSort(a, start, mid);
    printf("L: ");
    print_arr(left, leftLen);
    right = mergeSort(a, mid, end);
    
    printf("R: ");
    print_arr(right, rightLen);

    i = j = c = 0;
    while ((i < leftLen || j < rightLen) && c < len) {
        if (i < leftLen) {
            max = left[i];
        }
        i++;
        if (j < rightLen && right[j] > max) {
            max = right[j];
            j++;
            i--;
        }
        // printf("Selected: %d, %d\n", max, left[i]);
        result[c] = max;
        c++;
        max = -999999;
    }
    return result;
};

int main() {
    int a[] = {3,-10,2,5,-10,100};
    int l = 6;
    int i;
    int *b;
    b = mergeSort(a, 0, l);

    print_arr(b, sizeof(a) / sizeof(*a));
    return 0;
}

