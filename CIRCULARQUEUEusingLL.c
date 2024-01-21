#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;


void enqueue();
void dequeue();
void peek();
void display();


int main(){
    printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY\n");
    printf("ENTER CHOICE");
    int choice;
    scanf("%d",&choice);
    do{
        switch(choice){
            case 1: enqueue();
            break;

            case 2: dequeue();
            break;

            case 3: peek();
            break;

            case 4: display();
            break;

            default:printf("INVALID");
        }
    }while(choice!=5);
}

void enqueue(){
    struct node *newnode;
    int ch=1;
    do{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter element");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(front==0 && rear==0){
            front=rear=newnode;
            rear->next=front;
        }
        else{
            rear->next=newnode;
            rear=newnode;
            rear->next=front;
        }
        printf("do you want to continue (0 or 1)");
        scanf("%d",&ch);
    }while(ch!=0);
}

void dequeue(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0){
        printf("empty");
    }
    else if(front==rear){
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void peek(){
    if(front==0 && rear==0){
        printf("empty");
    }
    else{
        printf("%d",front->data);
    }    
}

void display(){
    struct node *temp;
    temp=front;
    if(front==0 && rear==0){
        printf("empty");
    }
    else{
        while(temp->next!=front){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }    
}