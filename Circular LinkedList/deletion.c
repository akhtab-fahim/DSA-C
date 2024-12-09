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

void deleteBeg(){
    struct node *temp = tail->next;
    if(tail==0){
        printf("Empty");
    }else if(temp == tail->next){   //only one node
        tail = 0;
        free(temp);
    }else{
        tail->next = temp->next;
        free(temp);
    }

}

void deleteEnd(){
    struct node *current = tail->next,* prevnode;
    
    if(tail==0){
        printf("Empty");
    }else if(current == tail->next){   //only one node
        tail = 0;
        free(current);
    }else{
        while(current->next != tail->next){
        prevnode = current;
        current = current->next;
    }
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
    return 0;
}