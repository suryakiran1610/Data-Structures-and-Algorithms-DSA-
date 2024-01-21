#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *tail,*head;

void createll();
void deletebeg();
void deleteend();
void deletepos();
void display();
int getlength();

int main(){
    int ch;
    do{
        printf("\n1.CREATECIRCULARLL\n2.DELETE AT BEGINING\n3.DELETE AT END\n4.DELETE AT POS\n5.DISPLAY\n");
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                createll();
            break;
            case 2:
                deletebeg();
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

void deletebeg(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("empty");
    }
    else if(head->next==head){
        head=tail=0;
        free(temp);
    }
    else{
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}


void deleteend() {
    struct node *temp;
    temp = tail;

    if (head == 0) {
        printf("empty");
    } else if (head->next == head) {
        head = tail = 0;
        free(temp);
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}



void deletepos(){
    struct node *temp;
    int pos,i=1,l;
    temp=head;
    printf("enter position");
    scanf("%d",&pos);
    l=getlength();
    if(pos<0 || pos>l){
        printf("invalid");
    }
    else if(pos==1){
        deletebeg();
    }
    else{
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        if(temp->next==head){
            tail=temp->prev;
            free(temp);
        }
        else{
            free(temp);
        }
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