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

int getLength() {
    int count = 0;
    struct node *temp = head;
    if (head != NULL) {
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    return count;
}

void deleteBeg() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == head) { // Only 1 node
        head = tail = NULL;
        free(temp);
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp = tail;
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == head) { // Only 1 node
        head = tail = NULL;
        free(temp);
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void deletePos() {
    struct node *temp = head;
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    int len = getLength(); // Validate position
    if (head == NULL) {
        printf("List is empty\n");
    } else if (pos < 1 || pos > len) {
        printf("Invalid position\n");
    } else if (pos == 1) {
        deleteBeg();
    } else {
        while (i < pos && temp->next != head) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == tail) { // If last node
            tail = temp->prev;
        }
        free(temp);
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
    deletePos();
    display();
    return 0;
}
