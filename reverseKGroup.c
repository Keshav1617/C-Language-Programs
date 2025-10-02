#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse nodes in k-group
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) {
        return head;
    }

    // Count length of list
    struct ListNode* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // If remaining nodes are less than k, return as it is
    if (count < k) {
        return head;
    }

    struct ListNode* currptr = head;
    struct ListNode* prevptr = NULL;
    struct ListNode* nextptr = NULL;

    int counter = 0;

    // Reverse k nodes
    while (currptr != NULL && counter < k) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        counter++;
    }

    // Recursively reverse remaining list
    if (currptr != NULL) {
        struct ListNode* new_head = reverseKGroup(currptr, k);
        head->next = new_head;
    }

    // prevptr is new head after reversing k nodes
    return prevptr;
}

// Utility function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Utility function to print linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Creating list: 1->2->3->4->5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list:\n");
    printList(head);

    int k = 2;
    head = reverseKGroup(head, k);

    printf("Reversed in groups of %d:\n", k);
    printList(head);

    return 0;
}
