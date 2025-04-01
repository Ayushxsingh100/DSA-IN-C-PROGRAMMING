#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode() {
    node *t;
    t = (node*)malloc(sizeof(node));
    return t;
}
 
node* insertatEnd(node* HN, int data) {
    node* tn = HN;
    if(tn == NULL) {
        tn = createNode();
        tn->data = data;
        tn->next = NULL;
        return tn;
    }   
    while(tn->next != NULL) {
        tn = tn->next;
    }
    tn->next = createNode();
    tn->next->data = data;
    tn->next->next = NULL;
    return HN;
}

struct node* merge(struct node*MYLL1 , struct node*MYLL2){
    struct node* current = merge;

  while (MYLL1 != NULL && MYLL2 != NULL) {
    if (MYLL1->data < MYLL2->data) {
        current = MYLL1;
        MYLL1 = MYLL1->next;
    } else {
        current = MYLL2;
        MYLL2 = MYLL2->next;
    }
     current->next = current;

}

}



    int main() {
        node* MYLL1 = NULL;
        MYLL1 = insertatEnd(MYLL1, 1);
        MYLL1 = insertatEnd(MYLL1, 5);
        MYLL1 = insertatEnd(MYLL1, 8);
        
        node* MYLL2 = NULL;
        MYLL2 = insertatEnd(MYLL2, 3);
        MYLL2 = insertatEnd(MYLL2, 4);
        MYLL2 = insertatEnd(MYLL2, 7);
        
}

