#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next; 
};

struct node * top = 0;
void push(int data){
    struct node * newnode;
    newnode = (struct node * )malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = top;
    top = newnode;
}

void pop(){
    struct node * temp;
    temp = top;
    if(top==0){
        printf("Stack is empty ");
    }else{
        printf("Item Popped %d \n",temp->data);
        top = temp->next;
        free(temp);
    }

}

void peek(){
    if(top==0){
        printf("Stack is empty ");
    }else{
        printf("Element at the top %d\n",top->data);
    }
}
void display(){
    struct node * temp;
    temp = top;
    if(top==0){
        printf("Stack is empty ");
    }else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }

}
int main(){
    push(12);
    push(13);
    push(14);
    push(15);
    peek();
    pop();
    display();
    return 0;
}
