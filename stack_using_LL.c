#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tp = NULL;

int isEmpty(struct node *top) {
      return top == NULL;
} 

int isFull(struct node *top) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        return 1;
    } else {
        free(p);
        return 0;
    }
}

struct node* push(struct node* top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
        return top; // Early return
    } else {
        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        printf("Pushed %d onto the stack\n", x);
    }
    return top;
}

struct node* pop(struct node *top) {
    if (isEmpty(top)) {
        printf("Stack Underflow\n");
        return top; // Early return
    } else {
        struct node *n = top;
        printf("Popped %d from the stack\n", n->data);
        top = top->next;
        free(n);
    }
    return top;
}

int main() {
    tp = push(tp, 28);
    tp = push(tp, 18);
    tp = push(tp, 15);
    tp = push(tp, 7);
    tp = pop(tp);
    tp = pop(tp);

    return 0;
}
