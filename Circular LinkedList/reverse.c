#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * head,* tail ;

void create(){
    struct node * newnode;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        newnode->next =0;
        if(tail == 0){
            tail = newnode;
            tail->next = newnode;
        }else{
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("want to add more 0/1 : ");
        scanf("%d",&choice);
    }
}

void reverse(){
    struct node * prevnode,* current,* nextnode;

    current = tail->next;
    nextnode = current->next;
    if(tail == 0){
        printf("List is Empty ");
    }else{
        while (current != tail)
        {
            prevnode = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prevnode;

        }
        nextnode->next = tail;
        tail = nextnode;
        
    }
}

void display(){
     struct node *temp = tail->next;
     if(tail == 0){
        printf("List is empty ");
     }else{
        while(temp->next != tail->next ){
        printf("%d -> ",temp->data);
        temp = temp->next;
        }
        printf("%d ",temp->data);

     }
     
}

int main(){
    create();
    display();
    reverse();
    printf("After reversing \n");
    display();
    return 0;
}