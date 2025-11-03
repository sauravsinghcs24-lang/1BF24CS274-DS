#include<stdio.h>
#define N 5;
int queue[5];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(front==(rear+1)%5){
        printf("Queue overflow:\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
           rear=(rear+1)%5;
           queue[rear]=x;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue underflow:");
    }
    else if(front==rear){
           printf("The removed element is:%d\n",queue[front]);
           front=rear=-1;
    }
    else{
        printf("The removed element is:%d\n",queue[front]);
        front=(front+1)%5;
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue underflow:");
    }
    else{
    printf("The queue contains:\n");
    for(int i=front;i<=rear;i=(i+1)%5){
        printf("%d \n",queue[i]);
    }
}
}
int main(){
     printf("Menu\n");
        printf("Enter 1. for enqueue,2.for dequeue,3. for display,4. for exit\n");
         while (1){
            int op;
        printf("Enter your choice:\n");
        scanf("%d",&op);
        switch(op){
            case 1:{
                     int x;
                     printf("Enter element to be inserted:");
                     scanf("%d",&x);
                     enqueue(x);
                     break;
            }
            case 2:
                    dequeue();
                    break;
            case 3:
                    display();
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    printf("Invalid:");
        }
    }
}
