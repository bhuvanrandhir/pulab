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
    if (*head == NULL) {
        newNode->next = newNode; // For circular list
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    if (*head == NULL) {
        insertAtBeginning(head, data);
    } else {
        struct Node* newNode = createNode(data);
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
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
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next != nextNode && temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = nextNode;
    temp->next = newNode;
    if (nextNode == *head) {
        *head = newNode;
    }
}

// Function to insert a node at specific position
void insertAtPosition(struct Node** head, int position, int data) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to search a particular node
struct Node* searchNode(struct Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        struct Node* temp = *head;
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == *head) { // Only one node
        free(*head);
        *head = NULL;
    } else {
        struct Node* prev = NULL;
        struct Node* current = *head;
        while (current->next != *head) {
            prev = current;
            current = current->next;
        }
        prev->next = *head;
        free(current);
    }
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
    if (*head == NULL || nextNode == NULL) {
        printf("Head node or Next node cannot be NULL\n");
        return;
    }
    if (nextNode->next == *head) { // If nextNode is head
        struct Node* temp = *head;
        while (temp->next != nextNode) {
            temp = temp->next;
        }
        temp->next = nextNode->next;
        free(nextNode);
    } else {
        struct Node* temp = *head;
        while (temp->next->next != nextNode) {
            temp = temp->next;
        }
        struct Node* deleteNode = temp->next;
        temp->next = nextNode;
        free(deleteNode);
    }
}

// Function to delete a particular node
void deleteNode(struct Node** head, struct Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Head node or Node to delete cannot be NULL\n");
        return;
    }
    if (*head == delNode) {
        deleteAtBeginning(head);
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
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp == *head) {
        printf("Position out of range\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
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
