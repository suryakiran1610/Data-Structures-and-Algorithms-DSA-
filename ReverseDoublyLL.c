#include<stdio.h>
#include<stdlib.h>

void createdll();
void reversedll();
void display();


struct node{
        int data;
        struct node *prev;
        struct node *next;
    };
struct node *head,*tail;

    void createdll() {
        struct node *newnode,*temp;
        head=0;
        int ch=1;
        while(ch){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter elements");
            scanf("%d",&newnode->data);
            newnode->prev=0;
            newnode->next=0;
            if(head==0){
                head=temp=newnode;
            }
            else{
                temp->next=newnode;
                newnode->prev=temp;
                temp=newnode;
            }
            printf("do you want to continue(0 or 1)");
            scanf("%d",&ch);
        }    
    }

    void reversedll(){
        struct node *currentnode,*nextnode;
        currentnode=head;
        while(currentnode!=0){
            nextnode=currentnode->next;
            currentnode->next=currentnode->prev;
            currentnode->prev=nextnode;
            currentnode=nextnode;
        }
        currentnode=head;
        head=tail;
        tail=currentnode;
    }



    void display(){
        struct node*temp;
        temp=head;
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    } 

int main(){
    createdll();
    reversedll();
    display();
}   