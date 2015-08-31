#include <stdio.h>

int binarySearch(int arr[], int start, int end, int val) {
    int pos = -1; // Return -1 for position if it was not found
    int mid = (start + end) / 2;

    if (end - start <= 0) {
        return pos;
    }

    // printf("Middle: %d\n", arr[mid]);
    if (arr[mid] == val) {
        return mid;
    }
    else if (arr[mid] > val) {
        pos = binarySearch(arr, start, mid, val);
    }
    else {
        pos = binarySearch(arr, mid + 1, end, val);
    }
    return pos;
}

int main() {
    int a[] = {1, 3, 4, 5, 8, 10};
    int len = sizeof(a) / sizeof(a[0]);

    int val = 11;
    int pos = binarySearch(a, 0, len, val);

    printf("Found %d at %d\n", val, pos);
    return 0;
}