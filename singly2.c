#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;   // global head pointer

// Function to create a linked list
void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    head = NULL;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;   // first node
        } else {
            temp->next = newNode;   // link new node
        }
        temp = newNode;  // move temp
    }

    printf("\nLinked list created successfully.\n");
}

// Function to display the list
void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the first node
void deleteFirst() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    temp = head;
    head = head->next;  // move head to next node
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Function to delete a node with a specific value
void deleteSpecific(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // If head holds the value
    if (head->data == value) {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }

    // Unlink and delete
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Function to delete the last node
void deleteLast() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Only one node
    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted element: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Main function
int main() {
    int n, choice, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    createList(n);

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Display List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specific Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSpecific(value);
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
