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

void deleteBeg(){
    if(head == 0){
        printf("List is empty nothing to delete ");
    }else{
        struct node * temp = head;
        head = temp->next;
        head->prev = 0;
        free(temp);
    }
}


void deleteBLast(){
    if(tail == 0){
        printf("List is empty nothing to delete ");
    }else{
        struct node * temp = tail;
        tail = temp->prev;
        tail->next =0; 
        free(temp);
    }
}

void deletePos(){
    int pos,i=1;
    struct node * temp = head;
    printf("Enter pos : ");
    scanf("%d",&pos);
    while(i<pos){
        temp = temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev = temp->prev;
    free(temp);
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
    insertBeg();
    insertPos();
    display();
    return 0;
}
