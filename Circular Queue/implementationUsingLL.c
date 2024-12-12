#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node * next};
struct node * front = 0,*rear = 0;
void enqueue(int x){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if(rear == 0){
        front = rear = newnode;
        rear->next = front;
    }else{
        rear->next = newnode;
        rear = newnode;
        newnode->next = front;
    }
}

void dequeue(){
    struct node * temp = front;
     if(front == 0 && rear == 0){
        printf("Queue is empty ");
     }else if(front == rear){
        front = rear = 0;
     }else{
        front = front->next;
        rear->next = front;
        free(temp);
     }
} 

void peek(){
    if(front == 0 && rear == 0){
        printf("Queue is empty ");
     }else{
        printf("%d",front->data);
     }
}