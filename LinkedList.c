#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node
    {
        int data;
        struct node * next;
    };
    struct node *head,*newnode,*temp;
    head=0;
    int ch;
    while(ch){
        newnode=(struct node *) malloc(sizeof(struct node));
        printf("enter number");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue(0 or 1)");
        scanf("%d",&ch);
    }
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}