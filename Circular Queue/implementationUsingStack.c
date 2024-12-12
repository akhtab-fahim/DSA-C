#include<stdio.h>'
int s1[5],s2[5];
int top1= -1,top2= -1;
int count = 0;

void push1(int x){
    if(top1 == 4){
        printf("Queue is Full ");
    }else{
        top1++;
        s1[top1] = x;
    }
}

int pop1(){
    int x;
    if(top1 == -1){
        printf("Queue is empty ");
    }else{
        x = s1[top1];
        top1--;
    }
    return x;
}

void push2(int x){
    if(top2 == 4){
        printf("Queue is Full ");
    }else{
        top2++;
        s2[top2] = x;
    }
}

int pop2(){
    int x;
    if(top2 == -1){
        printf("Queue is empty ");
    }else{
        x = s2[top2];
        top2--;
    }
    return x;
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    int x,y,z;
    if(top1 == -1 && top2 == -1){
        printf("Empty ");
    }else{
        for(int i = 0;i<count;i++){
            x = pop1();
            push2(x);
        }
        y = pop2();
        printf("Item Popped %d\n",y);
        count--;
        for(int i = 0;i<count;i++){
            z = pop2();
            push1(z);
        }
    }
}

void display(){
    for(int i = top1;i>=0;i++){
        printf("%d ",s1[i] );
    }
}

int main(){
    enqueue(5);
    enqueue(-1);
    enqueue(2);
    dequeue();
    display();
    return 0;
}