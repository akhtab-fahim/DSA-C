#include<stdio.h>

int queue[5];
int front = -1;
int rear = -1;

void enqueue(int data) {
    if ((rear + 1) % 5 == front) {
        printf("Queue is full\n");
        return;
    } 
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % 5;
    }
    queue[rear] = data;
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    } 
    printf("Item dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % 5;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    } 
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % 5;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    enqueue(20);
    enqueue(10);
    enqueue(40);
    enqueue(50);
    dequeue();
    enqueue(69);
    dequeue();
    display();
    return 0;
}
