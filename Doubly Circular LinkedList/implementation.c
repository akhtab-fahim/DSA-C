#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * prev;
    struct node * next;
};

struct node * head,* tail;

void create(){
    head == 0;
    int choice =1;
    while(choice){
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        if(head == 0){
            head = newnode;
            tail = newnode;
            head->next = head;
            head->prev = head;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("1 for insertion 0 for stop : ");
        scanf("%d",&choice);
    }
}

void display(){
    struct node * temp = head;
    if(head == 0 ){
        printf("List is Empty");
    }else{
        while(temp!= tail){
            printf(" %d ->",temp->data);
            temp = temp->next;
        }
        printf(" %d",temp->data);

    }


}

int main(){
    create();
    display();
    return 0;
}
