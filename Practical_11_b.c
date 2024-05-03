#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prevNode = NULL, *currNode = head, *nextNode = NULL;
    while (currNode != NULL) {
        nextNode = currNode->next; // Store next node
        currNode->next = prevNode; // Reverse current node's pointer
        prevNode = currNode;       // Move pointers one position ahead
        currNode = nextNode;
    }
    return prevNode; // Return the new head of the reversed list
}

// Function to check if the linked list is palindrome
bool isPalindrome(struct Node* head) {
    // Find the middle of the list
    struct Node *slowPtr = head, *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // If the length of the list is odd, move slow pointer one step forward
    if (fastPtr != NULL) {
        slowPtr = slowPtr->next;
    }

    // Reverse the second half of the list
    struct Node* reversedSecondHalf = reverseList(slowPtr);

    // Compare the first half with the reversed second half
    struct Node* firstHalf = head;
    while (reversedSecondHalf != NULL) {
        if (firstHalf->data != reversedSecondHalf->data) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true; // Palindrome
}

int main() {
    struct Node* head = NULL;

    // Inserting some nodes
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);

    printf("Original List: ");
    displayList(head);

    // Check if the list is palindrome
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
