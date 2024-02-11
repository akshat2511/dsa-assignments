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
struct Node* creation(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted successfully\n");
    return head;
}
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted successfully at the beginning.\n");
    return head;
}



struct Node* insert(struct Node* head, int index,int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        if(index<=1)head = insertAtBeginning(head, data);
        else{
        for(int i=1;i<index-1;i++){
            temp = temp->next;
        }
        
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }}

    printf("Node inserted successfully.\n");
    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete node.\n");
        return head;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            printf("Node with data %d deleted successfully.\n", data);
            return head;
        }
        temp = temp->next;
    }

    printf("Node with data %d not found in the list.\n", data);
    return head;
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

void menu() {
    printf("Choose operation Operations \n");
    printf("1. Creation and Addition of DLL\n");
    printf("2. Insert\n");
    printf("3. Delete a node\n");
    printf("4. Display the list\n");
    printf("5. Exit\n");
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    menu();
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = creation(head, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                int index;
                scanf("%d", &data);
                printf("Enter index at which you want node to be inserted: ");
                scanf("%d", &index);

                head = insert(head, index,data);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 5);
char a;
scanf("%d",a);
    return 0;
}

