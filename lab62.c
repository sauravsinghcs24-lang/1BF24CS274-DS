#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL, *head2 = NULL;


struct Node* createList(int n) {
    struct Node *head = NULL, *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(0);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked list created successfully.\n");
    return head;
}

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void sortList(struct Node *head) {
    struct Node *i, *j;
    int tempData;

    if (head == NULL) {
        printf("List is empty. Nothing to sort.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                tempData = i->data;
                i->data = j->data;
                j->data = tempData;
            }
        }
    }
    printf("Linked list sorted successfully.\n");
}


struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;
        curr = next;
    }

    printf("Linked list reversed successfully.\n");
    return prev; // new head
}


struct Node* concatenate(struct Node *head1, struct Node *head2) {
    struct Node *temp;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Linked lists concatenated successfully.\n");
    return head1;
}


int main() {
    int choice, n1, n2;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display First List\n");
        printf("4. Display Second List\n");
        printf("5. Sort First List\n");
        printf("6. Reverse First List\n");
        printf("7. Concatenate Two Lists\n");
        printf("8. Display Concatenated List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes for first list: ");
                scanf("%d", &n1);
                head1 = createList(n1);
                break;
            case 2:
                printf("Enter number of nodes for second list: ");
                scanf("%d", &n2);
                head2 = createList(n2);
                break;
            case 3:
                printf("First Linked List: ");
                displayList(head1);
                break;
            case 4:
                printf("Second Linked List: ");
                displayList(head2);
                break;
            case 5:
                sortList(head1);
                break;
            case 6:
                head1 = reverseList (head1);
                break;
            case 7:
                head1 = concatenate (head1, head2);
                head2 = NULL;
                break;
            case 8:
                printf("Concatenated Linked List: ");
                displayList(head1);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}