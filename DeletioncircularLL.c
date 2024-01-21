#include<stdio.h>
#include<stdlib.h>

void createll();
void deletestart();
void deleteend();
void deletepos();
void display();
int getlength();


struct node{
    int data;
    struct node *next;
};
struct node *head,*tail;


int main(){
    int ch;
    do{
        printf("1.CREATE LL\n2.DELETE START\n3.DELETE END\n4.DELETE POS\n5.DISPLAY\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createll();
                break;
            case 2:
                deletestart();
                break;
            case 3:
                deleteend();
                break;
            case 4:
                deletepos();
                break;
            case 5:
                display();
                break;
            default:
                printf("invalid");                    
        }
    }while (ch!=6);
        
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


void deletestart(){
    struct node *temp;
    temp=tail->next;
    if(tail==0){
        printf("empty");
    }
    else if(temp->next=temp){
        tail=0;
        free(temp);
    }
    else{
        tail->next=temp->next;
        free(temp);
    }
}


void deleteend(){
    struct node *current,*previous;
    current=tail->next;
    if(tail==0){
        printf("empty");
    }
    else if(current->next=current){
        tail=0;
        free(current);
    }
    else{
        while(current->next!=tail->next){
            previous=current;
            current=current->next;
        }
        previous->next=tail->next;
        tail=previous;
        free(current);
    }    
}


void deletepos(){
    struct node *current,*nextnode;
    int pos,i=1,l;
    current=tail->next;
    printf("enter position");
    scanf("%d",&pos);
    l=getlength();
    if(pos<1 || pos>l){
        printf("invalid");
    }
    else if(pos==1){
        deletestart();
    }
    else{
        while(i<pos-1){
            current=current->next;
            i++;
        }
    nextnode=current->next;
    current->next=nextnode->next;
    free(nextnode);
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



