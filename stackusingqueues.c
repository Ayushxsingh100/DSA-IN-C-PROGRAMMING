#include <stdio.h>
#include <stdlib.h>


 typedef struct Queue {
    int data;
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset queue
    } else {
        q->front++;
    }
    return value;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->data[q->front];
}

// Define the stack structure
typedef struct Stack {
    Queue queue1;
    Queue queue2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->queue1);
    initQueue(&s->queue2);
}

void push(Stack *s, int value) {
    enqueue(&s->queue1, value);
}

int pop(Stack *s) {
    if (isEmpty(&s->queue1)) {
        printf("Stack Underflow!\n");
        return -1;
    }

    // Transfer elements except the last one to queue2
    while (s->queue1.front != s->queue1.rear) {
        enqueue(&s->queue2, dequeue(&s->queue1));
    }

    // Pop the last element
    int poppedElement = dequeue(&s->queue1);

    // Swap the queues
    Queue temp = s->queue1;
    s->queue1 = s->queue2;
    s->queue2 = temp;

    return poppedElement;
}

int top(Stack *s) {
    if (isEmpty(&s->queue1)) {
        printf("Stack is Empty!\n");
        return -1;
    }

    // Transfer elements except the last one to queue2
    while (s->queue1.front != s->queue1.rear) {
        enqueue(&s->queue2, dequeue(&s->queue1));
    }

    // Get the last element (top of stack)
    int topElement = front(&s->queue1);

    // Transfer it to queue2
    enqueue(&s->queue2, dequeue(&s->queue1));

    // Swap the queues
    Queue temp = s->queue1;
    s->queue1 = s->queue2;
    s->queue2 = temp;

    return topElement;
}

int isStackEmpty(Stack *s) {
    return isEmpty(&s->queue1);
}

// Main function
int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Popped element: %d\n", pop(&stack)); // Output: 30
    printf("Top element: %d\n", top(&stack));   // Output: 20
    printf("Is stack empty: %d\n", isStackEmpty(&stack)); // Output: 0

    return 0;
}
