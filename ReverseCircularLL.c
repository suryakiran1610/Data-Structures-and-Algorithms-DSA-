#include<stdio.h>
#include<stdlib.h>

void createll();
void reversell();
void display();


struct node{
    int data;
    struct node *next;
};
struct node *tail;

void createll(){
    struct node *newnode;
    int choice=1;
    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("do you want to continue90 or 1");
        scanf("%d",&choice);
    }    
}

void reversell(){
    struct node *prev,*current,*nextnode;
    current=tail->next;
    nextnode=current->next;
    if(tail==0){
        printf("empty");
    }
    while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
    }
    nextnode->next=tail;
    tail=nextnode;
}


void display(){
    struct node *temp;
    if(tail==0){
        printf("invalid");
    }
    else{
        temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

int main(){
    createll();
    reversell();
    display();
}