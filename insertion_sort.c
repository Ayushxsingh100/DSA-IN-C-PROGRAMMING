#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;               // Data field to store the value
    struct node* next;      // Pointer to the next node
 };

// Function to insert a new node into a sorted linked list
struct node* sortedInsert(struct node* head, struct node* newNode) {
    // Base case: Insert at the head or into an empty list
    if (head == NULL || newNode->data < head->data) {
        newNode->next = head;  // Make the new node point to the current head
        return newNode;        // The new node becomes the new head
    }

    // Traverse the list to find the correct position for insertion
    struct node* current = head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;  // Move to the next node
    }

    // Insert the new node into the correct position
    newNode->next = current->next; // Point the new node to the next node
    current->next = newNode;       // Link the current node to the new node

    return head;  // Return the head of the list
}

// Helper function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the functionality
int main() {
    // Initialize the linked list
    struct node* head = NULL;

    // Create and insert new nodes
    head = sortedInsert(head, createNode(10));
    head = sortedInsert(head, createNode(5));
    head = sortedInsert(head, createNode(20));
    head = sortedInsert(head, createNode(15));

    // Print the sorted linked list
    printf("Sorted Linked List: ");
    printList(head);

    return 0;
}
