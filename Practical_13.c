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
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        if (*head == (*head)->next) { // Only one node
            *head = NULL;
        } else {
            *head = (*head)->next;
            temp->next = *head;
        }
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
