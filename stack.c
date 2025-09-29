#include<stdio.h>
#define MAX 5
int Stack[MAX];
int top=-1;
void push(int item){
    if(top== MAX-1){
        printf("overflow\n",item);
    }
    else{
         top++ ;
         Stack[top]=item;
         printf("%d pushed\n",item);

    }
}
void pop(){
    if(top==-1){
        printf("under flow\n");
    }
    else{
        int item=Stack[top];
        top--;
        printf("%d popped\n",item);
    }
}
void peek(){
    if (top==-1){
        printf("underflow");
    }
    else{
        printf("Top element=%d\n",Stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("Stack elements:");
        for(int i=top; i>=0; i--){
            printf("%d",Stack[i]);
        }
        printf("\n");
    }

}
int main(){
    int choice,item;
    while(1){
        printf("\n  Stack Menu  \n");
        printf("\n 1. PUSH \n");
        
        printf("\n 2. POP  \n");
        
        printf("\n 3. PEEK \n");
        
        printf("\n 4. DISPLAY  \n");
        
        printf("\n 5. EXIT  \n");
        
        printf(" Enter your choice: \n");
        scanf("%d",& choice);
        switch(choice){
            case1:
            printf("Enter element to push:");
            scanf("%d",&item);
            break;
            case2:
            pop();
            break;
            case3:
            peek();
            break;
            case4:
            display();
            break;
            case5:
            return 0;
            default:
            printf("Invalid choice!\n");
            


        }
        


    }
}