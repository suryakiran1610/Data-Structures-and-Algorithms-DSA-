#include<stdio.h>
#include<stdlib.h>
#define n 5
int s1[n];
int s2[n];
int top1=-1;
int top2=-1;
int count=0;

void enqueue();
void dequeue();
void display();
void push1(int data);
int pop1();
int pop2();
void push2(int data);


void enqueue(int x){
    push1(x);
    count++;
}
void dequeue(){
    int i,a,b;
    if(top1==-1 && top2==-1){
        printf("empty");
    }
    else{
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }        
        b=pop2();
        printf("the dequeue element is %d",b);

    }    
}

void push1(int data){
    if(top1==n-1){
        printf("overflow");
    }
    else{
        top1++;
        s1[top1]=data;
    }
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void push2(int data){
    if(top2==n-1){
        printf("overflow");
    }
    else{
        top2++;
        s2[top2]=data;
    }
}

void display() {
    int i;
    for (i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}


int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
   
}


