#include<stdio.h>
#include<stdlib.h>

void createll();
void deletestart();
void deleteend();
void deletepos();
void display();


struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode,*prenode,*nextnode;


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
    int choice=1;
    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter element");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue(0,1)");
        scanf("%d",&choice);
    }
    temp=head;
}


void deletestart(){
    temp=head;
    head=head->next;
    free(temp);
}



void deleteend(){
    temp=head;
    while(temp->next!=0){
        prenode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }
    else{
        prenode->next=0;
    }
    free(temp);
}




void deletepos(){
    int pos,i=1;
    temp=head;
    printf("enter position");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    free(newnode);

}



void display() {
    temp = head;
    while (temp != 0) {
        printf("The elements are %d\n", temp->data);
        temp = temp->next;
    }
}
