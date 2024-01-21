#include<stdio.h>
#include<stdlib.h>

    void createdll();
    void display();
    void insertatpos();
    void insertatend();
    void insertatbeg();

struct node{
        int data;
        struct node *prev;
        struct node *next;
    };

struct node *head,*newnode,*temp,*tail;
int ch;


int main(){
    do{
        printf("1.CREATE\n2.INSERTBEG\n3.INSERTEND\n4.INSERTPOS\n5.DISPLAY");
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createdll();
            break;

            case 2:
                insertatbeg();
            break;

            case 3:
                insertatend();
            break;

            case 4:
                insertatpos();
            break;

            case 5:
                display();
            break; 
            default:
                 printf("invalid");        
        }
    }while(ch!=6);
        
}    
    void createdll() {
        head=0;
        int ch=1;
        while(ch){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter elements");
            scanf("%d",&newnode->data);
            newnode->prev=0;
            newnode->next=0;
            if(head==0){
                head=tail=newnode;
            }
            else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
            }
            printf("do you want to continue(0 or 1)");
            scanf("%d",&ch);
        }    
    }

    void insertatbeg(){
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }


    void insertatend(){
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter element");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }


    void insertatpos(){
        int pos;
        printf("enter position");
        scanf("%d",&pos);
        if(pos==1){
            insertatbeg();
        }
        else{
            struct node *newnode,*temp;
            temp=head;
            int i=1;
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter element");
            scanf("%d",&newnode->data);
            newnode->next=0;
            newnode->prev=0;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            newnode->prev=temp;
            newnode->next=temp->next;
            temp->next=newnode;
            newnode->next->prev=newnode;
        }    
    }


    void display(){
        struct node*temp;
        temp=head;
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }    
