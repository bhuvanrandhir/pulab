#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node *prevNode = NULL, *currNode = *head, *nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next; // Store next node
        currNode->next = prevNode; // Reverse current node's pointer
        prevNode = currNode;       // Move pointers one position ahead
        currNode = nextNode;
    }
    *head = prevNode; // Adjust head to the new first node
}

int main() {
    struct Node* head = NULL;

    // Inserting some nodes
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    printf("Original List: ");
    displayList(head);

    // Reversing the list
    reverseList(&head);

    printf("Reversed List: ");
    displayList(head);

    return 0;
}
