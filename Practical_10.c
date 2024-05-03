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

// Function to insert a node after a particular node
void insertAfterNode(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to insert a node before a particular node
void insertBeforeNode(struct Node** head, struct Node* nextNode, int data) {
    if (*head == NULL || nextNode == NULL) {
        printf("Head node or Next node cannot be NULL\n");
        return;
    }
    if (*head == nextNode) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != nextNode) {
        temp = temp->next;
    }
    struct Node* newNode = createNode(data);
    newNode->next = nextNode;
    temp->next = newNode;
}

// Function to insert a node at specific position
void insertAtPosition(struct Node** head, int position, int data) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to search a particular node
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node after a particular node
void deleteAfterNode(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("Previous node or Next node cannot be NULL\n");
        return;
    }
    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);
}

// Function to delete a node before a particular node
void deleteBeforeNode(struct Node** head, struct Node* nextNode) {
    if (*head == NULL || nextNode == NULL || *head == nextNode) {
        printf("Head node or Next node cannot be NULL\n");
        return;
    }
    if ((*head)->next == nextNode) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != nextNode) {
        temp = temp->next;
    }
    struct Node* deleteNode = temp->next;
    temp->next = nextNode;
    free(deleteNode);
}

// Function to delete a particular node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Head node or Node to delete cannot be NULL\n");
        return;
    }
    if (*head == delNode) {
        *head = delNode->next;
        free(delNode);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != delNode) {
        temp = temp->next;
    }
    temp->next = delNode->next;
    free(delNode);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 0; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
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

int main() {
    struct Node* head = NULL;

    // Insertions
    insertAtBeginning(&head, 5);    // A. Insertion At Beginning
    insertAtEnd(&head, 7);          // B. Insertion At End
    struct Node* afterNode = searchNode(head, 5);
    if (afterNode != NULL) {
        insertAfterNode(afterNode, 6);  // C. Insertion After a particular node
    }
    struct Node* beforeNode = searchNode(head, 7);
    if (beforeNode != NULL) {
        insertBeforeNode(&head, beforeNode, 8); // D. Insertion Before a particular node
    }
    insertAtPosition(&head, 2, 9);  // E. Insertion at specific position
    displayList(head);

    // Search
    struct Node* searchResult = searchNode(head, 6);
    if (searchResult != NULL) {
        printf("Node 6 found.\n");
    } else {
        printf("Node 6 not found.\n");
    }

    // Deletions
    deleteAtBeginning(&head);   // H. Deletion at the beginning
    deleteAtEnd(&head);         // I. Deletion at the end
    deleteAfterNode(beforeNode); // J. Deletion after a particular node
    deleteBeforeNode(&head, searchNode(head, 6)); // K. Deletion before a particular node
    deleteNode(&head, searchNode(head, 8));       // L. Delete a particular node
    deleteAtPosition(&head, 1); // M. Deletion at a specific position
    displayList(head);

    return 0;
}
