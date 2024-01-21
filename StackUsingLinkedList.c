#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *top=0;

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
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&newnode->data);
    newnode->next=top;
    top=newnode;
}    

void pop(){
    struct node *temp;
    temp=top;
    if(top==0){
        printf("empty");
    }
    else{
        printf("the deleted element is%d",top->data);
        top=top->next;
        free(temp);
    }
}

void peek(){
    if(top==0){
        printf("empty");
    }
    else{
        printf("the top elementis %d",top->data);
    }
}

void display(){
    struct node *temp;
    temp=top;
    if(temp==0){
        printf("empty");
    }
    else{
        while(temp!=0){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}    
    