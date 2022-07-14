

// Circular array implementation

#include<stdio.h>
#define MAXSIZE=101;
int a[MAXSIZE];
int front=-1,rear=-1;

int IsEmpty(){
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}

int IsFull(){
    if((rear+1)%MAXSIZE==front)  // Checking if the first element(a[0]) is filled after reaching a[100] and so on... 
        return 1;
    else
        return 0;
}

void Enqueue(int x){
    if(IsEmpty()){
        front=0;
        rear=0;
    }
    else if(IsFull()){
        printf("The queue is full! \n");
    }
    else{
        rear=(rear+1)%MAXSIZE;
    }
    a[rear]=x;
}

void Dequeue(){
    if(IsEmpty())
        return;
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%MAXSIZE;
    }
}

int Front(){
    return a[front];
}

// Linked List Implementation

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;

void Enqueue(int x){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void Dequeue(){
    struct Node* temp=front;
    if(front==NULL)
        return;
    if(front==rear){
        front=NULL;
        rear==NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

int IsEmpty(){
    if(front==NULL)
        return 1;
    else
        return 0;
}

int Front(){
    return front->data;
}

void print_queue(){
    struct Node* temp=front;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    
}