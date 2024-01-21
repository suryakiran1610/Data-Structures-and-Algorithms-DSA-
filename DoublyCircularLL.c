#include<stdio.h>
#include<stdlib.h>

void createll();
void display();

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*tail;

void createll(){
    struct node *newnode;
    int ch=1;
    while(ch){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        
        if(head==0){
            tail=head=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("do you want to continue(0 or 1)");
        scanf("%d",&ch);
    }    
}

void display(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("empty");
    }
    else{
        while(temp!=tail){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d\t",temp->data);
    }
}

int main(){
    createll();
    display();
}