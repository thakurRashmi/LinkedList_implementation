#include <stdio.h>
#include <stdlib.h>

// Define the ListNode data structure
typedef struct ListNode
{
    int value;             // Value stored in the node
    struct ListNode* next; // Pointer to the next node
} ListNode;


// Function to insert a node at the end of the linked list
void insert(ListNode** headRef, int value) 
{
    // Create a new node
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->value = value;   // Set the value of the new node
    newNode->next = NULL;    // Since it's the last node, set next to NULL

    // If the list is empty, make the new node the head
    if (*headRef == NULL) 
    {
        *headRef = newNode;
    } 
     else 
     {
        // Traverse to the last node
        ListNode* lastNode = *headRef;
        while (lastNode->next != NULL) 
        {
            lastNode = lastNode->next;
        }
        // Attach the new node to the last node
        lastNode->next = newNode;
    }
}

// Function to delete a node with a given key
void deleteNode(ListNode** headRef, int key) 
{
    ListNode* currentNode = *headRef; // Current node being processed
    ListNode* prevNode = NULL;        // Previous node

    // If the key is found at the head
    if (currentNode != NULL && currentNode->value == key) 
    {
        *headRef = currentNode->next; // Change head to next node
        free(currentNode); // Free memory of the removed node
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (currentNode != NULL && currentNode->value != key)
    {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // If key was not present in linked list
    if (currentNode == NULL)
        return;

    // Unlink the node from linked list
    prevNode->next = currentNode->next;

    // Free memory
    free(currentNode);
}

// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

int main() {
    ListNode* head = NULL;

    // Insert some nodes
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Delete a node with value 2
    deleteNode(&head, 2);

    // Print the linked list after deletion
    printf("\nLinked List after deletion of node with value 2: ");
    printList(head);

    return 0;
}
