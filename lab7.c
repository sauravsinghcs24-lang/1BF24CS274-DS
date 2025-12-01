#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createList();
struct Node* createNode(int value);
void insertFront(struct Node **head, int value);
void insertEnd(struct Node **head, int value);
void deleteByValue(struct Node **head, int value);
void displayList(struct Node *head);

int main() {
    struct Node *head = createList();
    int choice, value;

    while (1) {
        printf("\n----- Doubly Linked List Menu -----\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
           
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&head, value);
            break;
        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            printf("Exiting...\n");
        
            while (head != NULL) {
                struct Node *temp = head;
                head = head->next;
                free(temp);
            }
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

struct Node* createList() {
    return NULL;
}


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertFront(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Inserted %d at the front.\n", value);
}


void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        printf("Inserted %d as the first node (end).\n", value);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", value);
}


void deleteByValue(struct Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;


    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
     
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    printf("Deleted node with value %d.\n", value);
    free(temp);
}


void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List contents: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
