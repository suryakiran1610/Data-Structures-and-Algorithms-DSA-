#include<stdio.h>
#include<conio.h>
#define n 10
int stack[n],top=-1;
void push();
void pop();
void display();
void peek();

int main(){
    int ch;
  do{
        printf("\n1. push\n2. pop\n3. display\n4.peek\n5. exit\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
            default:printf("error");
        }
    }while(ch!=5);
}
void push(){
    int x;
    printf("enter data");
    scanf("%d",&x);
    if(top==n-1){
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}    

void pop(){
    int item;
    if(top==-1){
        printf("stack underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("the deleted element is%d",item);
    }
}

void peek(){
    if(top==-1){
        printf("stack underflow");
    }
    else{
        printf("the top elementis %d",stack[top]);
    }
}

void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}    
    