#include<stdio.h>
#include<stdlib.h>

void circularll();
void display();

    struct node
    {
        int data;
        struct node * next;
    };
    struct node *head,*newnode,*temp;
    void circularll(){
        head=0;
        int ch=1;
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
            temp->next=head;
            printf("do you want to continue(0 or 1)");
            scanf("%d",&ch);
        }
    }

    void display(){  
        struct node*temp;  
        temp=head;
        while(temp->next!=head){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }

    int main(){
        circularll();
        display();
    }