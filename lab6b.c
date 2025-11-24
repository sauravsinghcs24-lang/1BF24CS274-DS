#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// STACK
void push(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack() {
    struct Node *temp = top;
    if (!temp) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// QUEUE
void enqueue(int value) {
    struct Node *newNode = createNode(value);
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("%d dequeued.\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue() {
    struct Node *temp = front;
    if (!temp) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// MAIN FUNCTION
int main() {
    int choice, value;

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        if (choice == 1) {      // STACK MENU
            while (1) {
                printf("\n--- STACK MENU ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display Stack\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;

                switch (choice) {
                    case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
                    case 2: pop(); break;
                    case 3: displayStack(); break;
                    default: printf("Invalid choice.\n");
                }
            }
        }

        else if (choice == 2) {
            while (1) {
                printf("\n--- QUEUE MENU ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Queue\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;

                switch (choice) {
                    case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
                    case 2: dequeue(); break;
                    case 3: displayQueue(); break;
                    default: printf("Invalid choice.\n");
                }
            }
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}