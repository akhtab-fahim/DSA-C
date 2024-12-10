#include<stdio.h>
int stack[5];
int top = -1;

void push(int x){
    if(top == 4 ){
        printf("Stack Overflow ! Stack is Full ");
    }else{
        top++;
        stack[top] = x;
    }   
}

void pop(){
    int item;
    if(top == -1){
        printf("Stack Underflow ! Stack is Empty ");
    }else{
        item = stack[top];
        top--;
    }
    printf("Item Popped %d \n",item);
}

void peek(){
    if(top == -1){
        printf("Stack Underflow ! Stack is Empty ");
    }else{
        printf("Topmost Element in the stack is %d \n",stack[top]);
    }
}

void display(){
    for(int i =top;i>=0;i--){
        printf("%d ",stack[i]);

    }
}

int main(){
    push(1);
    push(2);
    push(4);
    pop();
    peek();
    display();
    return 0;
}