#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp, *newnode;

void createll();
void insertbeg();
void insertend();
void insertpos();
void display();
void freell();

int main() {
    int ch;
    do {
        printf("1.CREATE LL\n2.INSERT-BEG\n3.INSERT-END\n4.INSERT-POS\n5.DISPLAY\n6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
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
                printf("Invalid choice\n");
        }
    } while(ch != 6);

    return 0;
}

void createll() {
    int choice = 1; 
    while(choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter elements: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (head == 0) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0, 1): ");
        scanf("%d", &choice);
    }
}

void insertbeg() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter elements: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

void insertend() {
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

void insertpos() {
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

void display() {
    temp = head;
    while (temp != 0) {
        printf("The elements are %d\n", temp->data);
        temp = temp->next;
    }
}
