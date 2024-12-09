#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * head,* tail;
void create(){
    head =0;
    int choice = 1;
    struct node * temp;
    printf("Enter elements into the linked list (0 to stop):\n");
    scanf("%d",&choice);
    while (choice) {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);

        newnode->next=0;
        newnode->prev=0;
        if(head == 0){
            head = newnode;
            tail = newnode;
            temp = head;
        }else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("want to add more nodes 0/1 ? ");
        scanf("%d",&choice);
    }
}

void reverse(){
    struct node * currentnode,* nextnode;
    if(head == 0){
        printf("List is emty cant reverse ");
    }else{
        currentnode = head;
        while(currentnode!=0){
            nextnode = currentnode->next;
            currentnode->next = currentnode->prev;
            currentnode->prev = nextnode;
            currentnode = nextnode;
        }
        //swapping head and tail 
        currentnode = head;
        head = tail;
        tail = currentnode;
    }
}


void display(){
    struct node * temp = head;
    while(temp!=0){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main(){
    create();
    display();
    reverse();
    display();
    return 0;
}
