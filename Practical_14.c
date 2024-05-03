#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a particular node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
}

// Function to insert a node before a particular node
void insertBeforeNode(struct Node** head, struct Node* nextNode, int data) {
    if (*head == NULL || nextNode == NULL) {
        printf("Head node or Next node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
    nextNode->prev = newNode;
}

// Function to search a particular node
struct Node* searchNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node not found\n");
    return NULL;
}

// Function to return a particular node
struct Node* returnNode(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position <= 0) {
        printf("Invalid position\n");
        return NULL;
    }
    struct Node* temp = head;
    int count = 1;
    do {
        if (count == position) {
            return temp;
        }
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("Position out of range\n");
    return NULL;
}

// Function to delete a node before a particular node
void deleteBeforeNode(struct Node** head, struct Node* nextNode) {
    if (*head == NULL || nextNode == NULL) {
        printf("Head node or Next node cannot be NULL\n");
        return;
    }
    if (nextNode->prev == NULL) { // If nextNode is head
        printf("No node to delete before the head\n");
        return;
    }
    struct Node* delNode = nextNode->prev;
    if (delNode->prev != NULL) {
        delNode->prev->next = nextNode;
    } else {
        *head = nextNode;
    }
    nextNode->prev = delNode->prev;
    free(delNode);
}

// Function to delete a particular node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Head node or Node to delete cannot be NULL\n");
        return;
    }
    if (delNode == *head) { // If delNode is head
        *head = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    free(delNode);
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insertions
    insertAfterNode(head, 5);    // A. Insertion After a particular node
    insertAfterNode(head, 7);
    insertAfterNode(head->next, 6);
    displayList(head);

    insertBeforeNode(&head, head->next->next, 8); // B. Insertion Before a particular node
    displayList(head);

    // Search
    struct Node* searchResult = searchNode(head, 6); // C. Search a particular node
    if (searchResult != NULL) {
        printf("Node 6 found.\n");
    }

    // Return a particular node
    struct Node* returnedNode = returnNode(head, 3); // D. Return a particular node
    if (returnedNode != NULL) {
        printf("Node at position 3: %d\n", returnedNode->data);
    }

    // Deletions
    deleteBeforeNode(&head, head->next->next); // E. Deletion before a particular node
    displayList(head);

    deleteNode(&head, head->next); // F. Delete a particular node
    displayList(head);

    return 0;
}
