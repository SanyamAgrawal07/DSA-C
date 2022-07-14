// Binary Tree

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 101

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

///////////////////////

struct Node* a[MAXSIZE];
int front=-1,rear=-1;

int IsEmpty(){
    if(front == -1 && rear == -1)
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

void Enqueue(struct Node* x){
    if(IsEmpty()){
        front=0;
        rear=0;
    }
    else if(IsFull()){
        printf("%d\n",x->data);
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

struct Node* Front(){
    return a[front];
}

// Implemented queue for bfs

struct Node* get_new_node(int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct Node* Insert(struct Node* root,int data){
    if(root==NULL){
        root=get_new_node(data);
        return root;
    }
    if(data<=(root->data)){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
}

int Search(struct Node* root,int data){
    if(root==NULL) return 0;
    if(root->data==data) return 1;
    if(data<=(root->data))
        return Search(root->left,data);
    else
        return Search(root->right,data);
}

void Level_order(struct Node* root){
    if(root->left!=NULL)
        Enqueue(root->left);
    if(root->right!=NULL)
        Enqueue(root->right);
    
    printf("%d\n",root->data);

    Dequeue();
    if(!IsEmpty())
        Level_order(a[front]);
}

void Pre_order(struct Node* root){    // Data Left Right
    if(root==NULL) return;

    printf("%d\n",root->data);

    Pre_order(root->left);
    Pre_order(root->right);
}

void In_order(struct Node* root){    // Left Data Right
    if(root==NULL) return;

    In_order(root->left);

    printf("%d\n",root->data);

    In_order(root->right);
}

void Post_order(struct Node* root){    // Left Right Data
    if(root==NULL) return;

    Post_order(root->left);

    Post_order(root->right);
    
    printf("%d\n",root->data);
}

int Is_Bst(struct Node* root,int minv,int maxv){    // Another approach is doing inorder traversal and see if list is sorted or not
    if(root==NULL) return 1;

    if(root->data>minv && root->data<=maxv 
        && Is_Bst(root->left,minv,root->data) 
        && Is_Bst(root->right,root->data,maxv)){
        return 1;
    }
    return 0;
}

struct Node* find_min(struct Node* root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node* Delete(struct Node* root,int data){
    if(root==NULL) return root;
    if(data<root->data)
        root->left=Delete(root->left,data);
    else if(data>root->data)
        root->right=Delete(root->right,data);
    else{
        // we have now found the node to be deleted
        // Case 1 - Leaf Node
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        // Case 2 - One child
        else if(root->left==NULL){
            struct Node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct Node* temp=root;
            root=root->left;
            free(temp);
        }
        // Case 3 - Two children
        else{
            struct Node* temp=find_min(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}

int Max(int a,int b){
    if(a>=b)
        return a;
    return b;
}

int find_height(struct Node* root){
    if(root==NULL) return -1;
    return (Max(find_height(root->left),find_height(root->right))+1);
}

int main(){
    struct Node* root;
    root=NULL;

    root=Insert(root,10);
    root=Insert(root,20);
    root=Insert(root,30);

    // int c=Search(root,50);
    // printf("%d",c);

    Enqueue(root);
    Level_order(root);
    // printf("%d %d\n",front,rear);
}

