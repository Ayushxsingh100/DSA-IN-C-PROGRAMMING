void removeLoop(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            break; 
        }
    }
    if (slow != fast) {
        return;
    }
    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    while (fast->next != slow) {
        fast = fast->next;
    }
    fast->next = NULL;
}