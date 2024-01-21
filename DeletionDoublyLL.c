#include<stdio.h>
#include<stdlib.h>

    void createdll();
    void display();
    void deleteatbeg();
    void deleteatend();
    void deleteatpos();

struct node{
        int data;
        struct node *prev;
        struct node *next;
    };

struct node *head,*newnode,*temp,*tail;
int ch;


int main(){
    do{
        printf("1.CREATE\n2.DELETEBEG\n3.DELETEEND\n4.DELETEPOS\n5.DISPLAY");
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createdll();
            break;

            case 2:
                deleteatbeg();
            break;

            case 3:
                deleteatend();
            break;

            case 4:
                deleteatpos();
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


void deleteatbeg(){
    struct node *temp;
    if(head==0){
        printf("empty");
    }
    else{
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}


void deleteatend(){
    struct node *temp;
    if(head==0){
        printf("empty");
    }
    else{
        temp=tail;
        tail->prev->next=0;
        tail=tail->prev;
        free(temp);
    }
}


void deleteatpos(){
    struct node *temp;
    temp=head;
    int pos,i=1;
    printf("enter position");
    scanf("%d",&pos);
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void display(){
    struct node*temp;
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}    