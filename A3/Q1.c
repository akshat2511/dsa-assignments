#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void intersection(struct Node* head1, struct Node* head2, struct Node** head3_ref) {
    struct Node* current1 = head1;
    while (current1 != NULL) {
        struct Node* current2 = head2;
        while (current2 != NULL) {
            if (current1->data == current2->data) {
                push(head3_ref, current1->data);
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
}

void unionList(struct Node* head1, struct Node* head2, struct Node** head_ref) {
    struct Node* current = head1;
    while (current != NULL) {
        push(head_ref, current->data);
        current = current->next;
    }
    current = head2;
    while (current != NULL) {
        struct Node* temp = *head_ref;
        while (temp != NULL) {
            if (current->data == temp->data)
                break;
            temp = temp->next;
        }
        if (temp == NULL)
            push(head_ref, current->data);
        current = current->next;
    }
}

int main() {
    struct Node* A = NULL;
    push(&A, 3);
    push(&A, 7);
    push(&A, 10);
    push(&A, 15);
    push(&A, 16);
    push(&A, 9);
    push(&A, 22);
    push(&A, 17);
    push(&A, 32);

    struct Node* B = NULL;
    push(&B, 16);
    push(&B, 2);
    push(&B, 9);
    push(&B, 13);
    push(&B, 47);
    push(&B, 8);
    push(&B, 10);
    push(&B, 1);
    push(&B, 28);

    struct Node* C = NULL;
    intersection(A, B, &C);
    printf("Intersection list: ");
    printList(C);

    struct Node* D = NULL;
    unionList(A, B, &D);
    printf("Union list: ");
    printList(D);

    return 0;
}	
