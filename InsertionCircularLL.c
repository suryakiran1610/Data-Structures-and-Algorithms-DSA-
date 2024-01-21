#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *tail;

void createll();
void insertbeg();
void insertend();
void insertpos();
void display();
int getlength();

int main(){
    int ch;
    do{
        printf("\n1.CREATECIRCULARLL\n2.INSERT AT BEGINING\n3.INSERT AT END\n4.INSEET AT POS\n5.DISPLAY\n");
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createll();
            break;
            case 2:
                insertbeg();
            break;
            case 3:
                insertend();
            break;
            case 4:
                insertpos();
            break;
            case 5:
                display();
            break;
            default:
                printf("invalid");                    
        }
    }while(ch!=6);
}

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

void insertbeg(){
    struct node *newnode;
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
        }    
}


void insertend(){    
    struct node *newnode;
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
}


void insertpos(){
    struct node *newnode,*temp;
    int pos,i=1,l;
    printf("enter position");
    scanf("%d",&pos);
    l=getlength();
    if(pos<0 || pos>l){
        printf("invalid");
    }
    else if(pos==1){
        insertbeg();
    }
    else{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        newnode->next=0;
        temp=tail->next;
        while(i>pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

int getlength(){
    int count=0;
    struct node *temp;
    temp=tail->next;
    do{
        count++;
        temp=temp->next;
    }while(temp!=tail->next);
    return count;
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