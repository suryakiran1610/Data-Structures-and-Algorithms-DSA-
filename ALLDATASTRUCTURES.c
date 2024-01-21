#include<stdio.h>
#include<stdlib.h>

int arr[20];
int size;

struct node{
    int data;
    struct node *next;
};
struct node *head=0;
struct node *temp;
struct node *newnode;
struct node *prenode;
struct node * nextnode;
struct node *prev;
struct node *next;
struct node *tail;



void ARRAY();
    void CREATEARRAY();
    void INSERTBEG();
    void INSERTEND();
    void INSERTPOS();
    void DELETEBEG();
    void DELETEEND();
    void DELETEPOS();
    void DISPLAY();

void SINGLYLINKEDLIST();
    void CREATELL();
    void INSERTBEGLL();
    void INSERTENDLL();
    void INSERTPOSLL();
    void DELETEBEGLL();
    void DELETEENDLL();
    void DELETEPOSLL();
    void DISPLAYLL();

void DOUBLYLINKEDLIST();
    void CREATEDLL();
    void INSERTBEGDLL();
    void INSERTENDDLL();
    void INSERTPOSDLL();
    void DELETEBEGDLL();
    void DELETEENDDLL();
    void DELETEPOSDLL();
    void DISPLAYDLL();


int main(){
    int ch;
    printf("1.ARRAY\n2.LINKED LIST\n3.STACK\n4.QUEUE\n");
    printf("enter choice");
    scanf("%d",&ch);
    switch(ch){
        case 1:ARRAY();
        break;
        case 2:
            int choice2;
            printf("1.SINGLY LINKEDLIST\n2.DOUBLY LINKEDLIST\n3.CIRCULAR LINKEDLIST\n4.DOUBLY CIRCULAR LINKEDLIST\n");
            printf("enter choice");
            scanf("%d",&choice2);
            switch(choice2){
                case 1:SINGLYLINKEDLIST();
                break;
                case 2:DOUBLYLINKEDLIST();
                break;
               // case 3:CIRCULARLINKEDLIST();
               // break;
                //case 4:DOUBLYCIRCULARLINKEDLIST();
                //break;
                //default:printf("invalid");
            }
        break;
    }
}

//*********************************// ARRAY OPERATIONS//****************************************//

void ARRAY(){
    int choice1;
    do{
        printf("1.CREATE ARRAY\n2.INSERT BEG\n3.INSERT END\n4.INSERT POS\n5.DELETE BEG\n6.DELETE END\n7.DELETE POS\n8.DISPLAY\n");
        printf("select your choice");
        scanf("%d",&choice1);
        switch(choice1){
            case 1:CREATEARRAY();
            break;
            case 2:INSERTBEG();
            break;
            case 3:INSERTEND();
            break;
            case 4:INSERTPOS();
            break;
            case 5:DELETEBEG();
            break;
            case 6:DELETEEND();
            break;
            case 7:DELETEPOS();
            break;
            case 8:DISPLAY();
            break;
            default:printf("INVALID");
        }
    }while(choice1!=9);    
}

void CREATEARRAY(){
    printf("enter size of array");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("enter elements");
        scanf("%d",&arr[i]);
    }
}

void INSERTBEG(){
    int num;
    printf("enter element");
    scanf("%d",&num);
    for(int i=size-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=num;
    size++;
}

void INSERTEND(){
    int num;
    printf("enter element");
    scanf("%d",&num);
    arr[size]=num;
    size++;
}

void INSERTPOS(){
    int pos,num;
    printf("enter number to insert");
    scanf("%d",&num);
    printf("enter position to insert");
    scanf("%d",&pos);
    for(int i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
}

void DELETEBEG(){
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}

void DELETEEND(){
    size--;
}

void DELETEPOS(){
    int pos;
    printf("enter position");
    scanf("%d",&pos);
    for(int i=pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
}

void DISPLAY(){
    for(int i=0;i<size;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}

/********************************///***************************//



//********************//SINGLY LINKED LIST********************//

void SINGLYLINKEDLIST(){
    int choice3;
    printf("1.CREATE LINKEDLIST\n2.INSERT BEGNING\n3.INSERT END\n4.INSERT POSITION\n5.DELETE BEGINING\n6.DELETE END\n7.DELETE POSITION\n8.DISPLAY\n");
    printf("your choice");
    scanf("%d",&choice3);
    switch(choice3){
        case 1:CREATELL();
        break;
        case 2:INSERTBEGLL();
        break;
        case 3:INSERTENDLL();
        break;
        case 4:INSERTPOSLL();
        break;
        case 5:DELETEBEGLL();
        break;
        case 6:DELETEENDLL();
        break;
        case 7:DELETEPOSLL();
        break;
        case 8:DISPLAYLL();
        break;
        default:printf("invalid");    

    }
}

void CREATELL(){
    int ch=1;
    while(ch){
        newnode=(struct node*)malloc(sizeof(struct node));
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
        printf("0:to continue or 1:to exit");
        scanf("%d",&ch);
    }
    temp=head;
}

void INSERTBEGLL(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter element");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->next=head;
    head=newnode;
}

void INSERTENDLL(){
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter elements: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0) {
        head = temp = newnode;
    } else {
        temp = head;
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void INSERTPOSLL(){
    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = head;
    while (i < pos - 1 && temp != 0) {
        temp = temp->next;
        i++;
    }
    if (temp == 0) {
        printf("Invalid position\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter elements: ");
    scanf("%d", &newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void DELETEBEGLL(){
    temp=head;
    head=head->next;
    free(temp);
}

void DELETEENDLL(){
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

void DELETEPOSLL(){
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

void DISPLAYLL(){
    temp = head;
    while (temp != 0) {
        printf("The elements are %d\n", temp->data);
        temp = temp->next;
    }
}

//***********************************//*************************************************************************//


void DOUBLYLINKEDLIST(){
    int choice3;
    printf("1.CREATE DOUBLY LINKEDLIST\n2.INSERT BEGNING\n3.INSERT END\n4.INSERT POSITION\n5.DELETE BEGINING\n6.DELETE END\n7.DELETE POSITION\n8.DISPLAY\n");
    printf("your choice");
    scanf("%d",&choice3);
    switch(choice3){
        case 1:CREATEDLL();
        break;
        case 2:INSERTBEGDLL();
        break;
        case 3:INSERTENDDLL();
        break;
        case 4:INSERTPOSDLL();
        break;
        case 5:DELETEBEGDLL();
        break;
        case 6:DELETEENDDLL();
        break;
        case 7:DELETEPOSDLL();
        break;
        case 8:DISPLAYDLL();
        break;
        default:printf("invalid");    

    }
}


void CREATEDLL(){
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

void INSERTBEGDLL(){
        struct node *prev;
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

void INSERTENDDLL(){
        struct node *prev;
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

void INSERTPOSDLL(){
        int pos;
        printf("enter position");
        scanf("%d",&pos);
        if(pos==1){
            INSERTBEGDLL();
        }
        else{
            struct node *prev;
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

void DELETEBEGDLL(){
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

void DELETEENDDLL(){
    struct node *prev;
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

void DELETEPOSDLL(){
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

void DISPLAYDLL(){
        struct node*temp;
        temp=head;
        while(temp!=0){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
}
