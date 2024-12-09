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
//inserting at begining  
void insertBeg(){
    struct node * newnode = (struct node * )malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    newnode->prev =0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}


//inserting at last  
void insertLast(){
    struct node * newnode = (struct node * )malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&newnode->data);
    tail->next = newnode;
    newnode->prev =tail;
    head->prev = newnode;
    tail = newnode;
}

//inserting at given pos  
void insertPos(){
    int pos,i=1,length =0;
    printf("Enter the pos : ");
    scanf("%d",&pos);
    //length of LL
    struct node * len = head;
    while(head->next!=0){
        length++;
        len = len->next;
    }

    if(pos > 0 && pos<length ){
        printf("Invalid Position ");
    }else if(pos == 1 ){
        insertBeg();
    }else{
        struct node * newnode = (struct node * )malloc(sizeof(struct node));
        struct node * temp = head;
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->prev =temp;
        newnode->next = temp->next;
        temp->next=newnode;
        newnode->next->prev = newnode;
    }

}

//inserting after given pos  
void insertAfterPos(){
    int pos,i=1,length =0;
    printf("Enter the pos : ");
    scanf("%d",&pos);
    //length of LL
    struct node * len = head;
    while(head->next!=0){
        length++;
        len = len->next;
    }

    if(pos > 0 && pos<length ){
        printf("Invalid Position ");
    }else{
        struct node * newnode = (struct node * )malloc(sizeof(struct node));
        struct node * temp = head;
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        while(i<pos){
            temp = temp->next;
            i++;
        }
        newnode->prev =temp;
        newnode->next = temp->next;
        temp->next=newnode;
        newnode->next->prev = newnode;
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
    insertBeg();
    insertPos();
    display();
    return 0;
}
