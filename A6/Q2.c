#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

void insert(Queue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX_SIZE;

    q->data[q->rear] = item;
}

int delete(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot delete element.\n");
        return -1;
    }

    int item = q->data[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX_SIZE;

    return item;
}

void push(Queue *q, int item) {
    insert(q, item);
}

int pop(Queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1;
    }

    Queue tempQueue;
    initialize(&tempQueue);

    while (q->rear != q->front) {
        int item = delete(q);
        if (!isEmpty(q))
            insert(&tempQueue, item);
        else
            return item;
    }

    *q = tempQueue;

    return -1;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = q->front;

    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }

    printf("%d\n", q->data[i]);
}

int main() {
    Queue q;
    initialize(&q);

    int choice, item;

    printf("Enter the initial queue (-1 to stop):\n");

    while (1) {
        scanf("%d", &item);
        if (item == -1)
            break;
        insert(&q, item);
    }

    display(&q);

    printf("Stack operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("-1. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(&q, item);
                display(&q);
                break;
            case 2:
                item = pop(&q);
                if (item !=  -1)
                    printf("Popped item: %d\n", item);
                display(&q);
                break;
            case -1:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

