// Reference material:
// http://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/MIT6_006F11_lec04.pdf
// https://www.youtube.com/watch?v=B7hVxCmfPtM

#include <stdio.h>

struct maxHeap {
    int size;
    int *arr;
};

int getParentIndex(int currentI) {
    return (currentI -1) / 2;
}
int getLeftChildIndex(int currentI) {
    return 2 * currentI + 1;
}
int getRightChildIndex(int currentI) {
    return 2 * currentI + 2;
}

// Given a "node" (actually an index of the array), it'll heapify that node, with respect to only its direct children. We
// assume that everything below it is already heapified.
void maxHeapify(struct maxHeap heap, int index) {
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);
    int maxIndex = index;
    int temp;
    if (left < heap.size && heap.arr[left] > heap.arr[index]) {
        maxIndex = left;
    }
    if (right < heap.size && heap.arr[right] > heap.arr[left]) {
        maxIndex = right;
    }

    if (maxIndex == index) {
        // Already max-heapified
        return;
    }
    // Swap index with maxIndex
    temp = heap.arr[index];
    heap.arr[index] = heap.arr[maxIndex];
    heap.arr[maxIndex] = temp;

    // We may have messed the tree up, so we need to re-max-heapify it at the exchanged node
    maxHeapify(heap, maxIndex);
}


void buildMaxHeap(struct maxHeap heap) {
    int i;
    for (i = heap.size / 2 - 1; i >= 0; i--) {
        // i is chosen so that we skip all the leaf nodes (since they're already maxHeapified)
        maxHeapify(heap, i);
    }
}

void heapSort(struct maxHeap heap) {
    buildMaxHeap(heap);
    while (heap.size > 0) {
        int temp;
        temp = heap.arr[0];
        heap.arr[0] = heap.arr[heap.size - 1];
        heap.arr[heap.size - 1] = temp;
        heap.size--;
        maxHeapify(heap, 0);
    }
}

int main() {
    int i;
    int arr[] = {5, 3, 4, 8, 20, 1, 6};
    struct maxHeap heap;
    heap.arr = arr;
    heap.size = 7;

    heapSort(heap);

    for (i = 0; i < 6; i++) {
        printf("%d, ", heap.arr[i]);
    }
    printf("%d\n", heap.arr[i]);
}