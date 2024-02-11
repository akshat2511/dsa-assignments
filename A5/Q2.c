#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void interchangeValues(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node* start = head;
    struct Node* end = head;
    while (end->next != NULL) {
        end = end->next;
    }

    while (start != end && start->prev != end) {int temp;
       temp = start->data;
        start->data=end->data;
        end->data=temp;
        
        start = start->next;
        end = end->prev;
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list:\n");
    display(head);

    interchangeValues(head);

    printf("List after interchanging values:\n");
    display(head);
char a;
scanf("%d",a);
    return 0;
}
