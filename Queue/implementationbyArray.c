#include<stdio.h>
int queue[5];
int front = -1;
int rear = -1;
void enqueue(int data){
    if(rear == 4){
        printf("Queue is full ! ");
    }else if(front==-1 && rear == -1){
        front=rear=0;
    }else{
        rear++;
        queue[rear] = data;
    }
}

void dequeue(){
    if(front==-1 && rear == -1){
        printf("Queue is empty");
    }else if(front == rear){
        front=rear=-1;
    }else{
        printf("Item dequed %d\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1 && rear == -1){
        printf("Queue is empty");
    }else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    
}
int main(){
    enqueue(20);
    enqueue(10);
    enqueue(40);
    dequeue();
    display();
    return 0;
}