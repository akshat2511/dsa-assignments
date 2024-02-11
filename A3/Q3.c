#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node *mergeLists(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    struct Node *result = NULL;
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = mergeLists(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeLists(head1, head2->next);
    }
    return result;
}

int main()
{
    struct Node *head1 = NULL;
    push(&head1, 15);
    push(&head1, 10);
    push(&head1, 5);

    struct Node *head2 = NULL;
    push(&head2, 20);
    push(&head2, 3);
    push(&head2, 2);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    struct Node *mergedList = mergeLists(head1, head2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
