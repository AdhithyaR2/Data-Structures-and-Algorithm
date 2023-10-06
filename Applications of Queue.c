#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// Initialize the queue
void initialize(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the queue is full
int isFull(struct Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full! Cannot enqueue element.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
            queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % MAX_SIZE;
        }
        queue->arr[queue->rear] = value;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot dequeue element.\n");
        return -1; // Return a sentinel value
    } else {
        int dequeuedValue = queue->arr[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return dequeuedValue;
    }
}

// Display the elements of the queue
void display(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = queue->front;
        while (i != queue->rear) {
            printf("%d ", queue->arr[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue->arr[i]);
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    int dequeued = dequeue(&queue);
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
    }

    display(&queue);

    return 0;
}
