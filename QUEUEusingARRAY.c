#include<stdio.h>
#include<stdlib.h>

# define n 6
int queue[n];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void peek();
void display();


int main(){
    printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY");
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
    int ch=1;
    while(ch){
        int x;
        printf("enter data");
        scanf("%d",&x);
        if(rear==n-1){
            printf("full");
        }
        else if(front==-1&&rear==-1){
            front=rear=0;
            queue[rear]=x;
        }
        else{
            rear++;
            queue[rear=x];
        }
        printf("do you want to continue (0 or 1)");
        scanf("%d",&ch);
    }    
        
}

void dequeue(){
    if(front==-1&&rear==-1){
        printf("empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
}

void peek(){
    if(front==-1&&rear==-1){
        printf("empty");
    }
    else{
        printf("the front element is%d",queue[front]);
    }    
}

void display(){
    if(front==-1&&rear==-1){
        printf("empty");
    }
    else{
        for(int i=front;i<rear+1;i++){
            printf("%d",queue[i]);
        }
    }
}