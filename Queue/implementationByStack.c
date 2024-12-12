#include<stdio.h>

int s1[5], s2[5];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int x) {
    if (top1 == 4) {
        printf("Queue is full\n");
        return;
    }
    top1++;
    s1[top1] = x;
}

int pop1() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = s1[top1];
    top1--;
    return x;
}

void push2(int x) {
    if (top2 == 4) {
        printf("Queue is full\n");
        return;
    }
    top2++;
    s2[top2] = x;
}

int pop2() {
    if (top2 == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = s2[top2];
    top2--;
    return x;
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        int x = pop1();
        if (x != -1) {
            push2(x);
        }
    }
    int y = pop2();
    if (y != -1) {
        printf("Item dequeued: %d\n", y);
        count--;
    }
    for (int i = 0; i < count; i++) {
        int z = pop2();
        if (z != -1) {
            push1(z);
        }
    }
}

void display() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(4);
    enqueue(2);
    dequeue();
    display();
    return 0;
}
