#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front = -1, rear = -1;

void insert() {
int item;
if (rear == N - 1) {
printf("\n Queue Overflow the queue is full \n");
} else {
printf("Enter the element to insert: ");
scanf("%d", &item);
if (front == -1) {
front = 0;
}
rear++;
queue[rear] = item;
printf("Inserted %d into the queue.\n", item);
}
}
void delete() {
if (front == -1 || front > rear) {
printf("\nQueue Underflow (Queue is Empty)\n");
} else {
printf("Deleted element: %d\n", queue[front]);
front++;
if (front > rear) {
front = rear = -1;
}
}
}
void display() {
int i;
if (front == -1) {
printf("\nQueue is Empty\n");
} else {
printf("\nQueue elements are:\n");
for (i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n");
}
}
int main() {
int choice;
while (1) {
printf(" queue menu\n ");
printf("1.insert an element\n ");
printf("2.delete an element\n ");
printf("3.display an element\n ");
printf("4.exit the program\n ");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf(" you have Exited the program.\n");
exit(0);
default:
printf("Invalid choice!.\n");
}
}
return 0;
}
