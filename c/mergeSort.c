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
    int min = 999999;
    if (len <= 1) {
        result[0] = a[start];
        return result;
    }

    left = mergeSort(a, start, mid);
    right = mergeSort(a, mid, end);
    

    i = j = c = 0;
    while ((i < leftLen || j < rightLen) && c < len) {
        if (i < leftLen) {
            min = left[i];
        }
        i++;
        if (j < rightLen && right[j] < min) {
            min = right[j];
            j++;
            i--;
        }
        // printf("Selected: %d, %d\n", min, left[i]);
        result[c] = min;
        c++;
        min = 999999;
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

