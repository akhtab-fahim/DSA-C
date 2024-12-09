#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void create() {
    int choice = 1;
    while (choice) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("1 for insertion, 0 for stop: ");
        scanf("%d", &choice);
    }
}

void insertBeg() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    } else {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode; // Corrected `-` to `=`
        head = newnode;
    }
}

void insertEnd() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = tail = newnode;
        newnode->prev = tail;
        newnode->next = head;
    } else {
        newnode->prev = tail;
        tail->next = newnode; // Corrected `-` to `=`
        newnode->next = head;
        tail = newnode;
        head->prev = newnode;
    }
}

void insertAtPos() {
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position\n");
    } else if (pos == 1) {
        insertBeg();
    } else {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        printf("List elements: ");
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    create();
    insertAtPos();
    insertEnd();
    display();
    return 0;
}
