#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *temp,*newnode,*head,*currentnode,*prevnode,*nextnode;

void createll();
void reversell();
void display();


int main(){
    int choice;
    printf("1.createLL\n2.ReverseLL\n3.Display");
    printf("enter your choice");
    scanf("%d",&choice);
    do{
        switch(choice){
            case 1: 
                createll();
            break;
            case 2:
                reversell();
            break;
            case 3:
                display();
            break;
            default:printf("invalid");        
        }
    }while(choice!=4);
}

void createll(){
        head=0;
        int ch=1;
        while (ch==1)
        {
            newnode=(struct node *) malloc (sizeof(struct node));
            printf("enter elements");
            scanf("%d",&newnode->data);
            newnode->next=0;
            if(head=0){
                newnode=head=temp;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            printf("do you want to continue(0 or 1)");
            scanf("%d",&ch);
        }
        temp=head;
}       

//REVERSE LINKED LIST//
void reversell(){

    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}    


//PRINT LINKED LIST//

void display(){
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}    
