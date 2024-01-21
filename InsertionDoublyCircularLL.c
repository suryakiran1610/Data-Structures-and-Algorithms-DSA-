#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail,*head;

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

void insertbeg(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            tail=head=newnode;
            newnode->prev=head;
            newnode->next=head;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            newnode->prev=tail;
            tail->next=newnode;
            head=newnode;
        }    
}


void insertend(){    
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter elements");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            tail=head=newnode;
            newnode->prev=head;
            newnode->next=head;
        }
        else{
            newnode->prev=tail;
            tail->next=newnode;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }    
}


void insertpos(){
    struct node *newnode,*temp;
    int pos,i=1,l;
    temp=head;
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
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
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
    temp=head;
    if(head==0){
        printf("empty");
    }
    else{
        while(temp!=tail){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}