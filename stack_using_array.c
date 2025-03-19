#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int *arr;
    int top;
};

int isFull(struct stack *ptr) {
    if (ptr->top == ptr->size - 1) {  // Corrected logical error
        return 1;  // Stack is full
    }
    return 0;  // Stack is not full
}

int isEmpty(struct stack *ptr) {
    if (ptr->top == -1) {  // If top is -1, stack is empty
        return 1;  // Stack is empty
    }
    return 0;  // Stack is not empty
}

void push(struct stack *ptr, int value) {
    if (isFull(ptr)) {
        printf("The stack is overflowed. Cannot push %d.\n", value);
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("The stack is underflowed. Cannot pop.\n");
        return -1;  // Indicates stack underflow
    } else {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped %d from the stack.\n", value);
        return value;
    }
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // Push elements onto the stack
    push(sp, 56);
    push(sp, 45);
    push(sp, 32);
    push(sp, 89);
    push(sp, 46);
    push(sp, 78);
    push(sp, 89);  // This push will not succeed as the stack is full

    // Pop elements from the stack
    pop(sp);
    pop(sp);


    return 0;
}
