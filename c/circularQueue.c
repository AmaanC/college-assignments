#include <stdio.h>

#define MAX 5

struct queue {
    int arr[MAX];
    int head;
    int tail;
} q;

void init(struct queue *q) {
    q->head = 0;
    q->tail = 0;
}

void enqueue(struct queue *q, int val) {
    if ( (q->tail + 1) % MAX == q->head ) {
        printf("Queue full\n");
        return;
    }
    q->arr[q->tail] = val;
    q->tail = (q->tail + 1) % MAX;
}

int dequeue(struct queue *q) {
    int ret = -1;
    if (q->head == q->tail) {
        printf("Queue is empty\n");
        return ret;
    }
    ret = q->arr[q->head];
    q->head = (q->head + 1) % MAX;

    printf("%d\n", ret);
    return ret;
}

int main() {
    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    dequeue(&q);
    return 0;
}