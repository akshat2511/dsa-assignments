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

void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    struct Node* current = head;
    while (current != NULL) {
        push(head1_ref, current->data);
        current = current->next;
        if (current != NULL) {
            push(head2_ref, current->data);
            current = current->next;
        }
    }
}

int main() {
    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    splitList(head, &head1, &head2);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    return 0;
}
