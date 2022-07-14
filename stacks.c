// Array based implementation

#include<stdio.h>
#define MAX_SIZE 101
int a[MAX_SIZE];
int top= -1;

void Push(int x){
    if(top<=MAX_SIZE-1){
        a[++top]=x;
    }
}

void Pop(){
    if(top>=0){
        top--;
    }
}

void Print(){
    printf("Stack: ");
    for(int i=0 ; i<=top ; i++){
        printf(" %d",a[i]);
    }
    printf("\n");
}

// Linked List based implementation

struct Node{
    int data;
    struct Node* link;
};
struct Node* top;

void Push(){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  // We typecast here bcoz malloc returns void pointer n we need a pointer to node
    temp->data=x;
    temp->next=NULL;
    if(head != NULL)
        temp->next = top;
    top=temp;
}

void Pop(){
    struct Node* temp;
    if(top==NULL) return;
    temp=top;
    top=top->link;
    free(temp);
}

int main(){

}