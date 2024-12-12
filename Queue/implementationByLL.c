#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * head =0,*tail =0;
void enqueue(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next=0;
    if(head==0&&tail==0){
        head=tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}

void dequeue(){
    struct node * temp = head;
    if(head==0&&tail==0){
       printf("Empty");
    }else{
        printf("Item dequed %d\n",head->data);
        head = head->next;
        free(temp);
    }
}

void display(){
    struct node * temp = head;
    if(head==0&&tail==0){
       printf("Empty");
    }else{
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    enqueue(20);
    enqueue(10);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}


