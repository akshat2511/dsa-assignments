#include <stdio.h>
void insertionsort(int a[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}
void selectionsort(int a[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;

    }
}
void bubblesort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to insert a value into BST
struct Node* insertNode(struct Node* root, int value) {
    // Base case: If the tree is empty, return a new node
    if (root == NULL)
        return createNode(value);

    // Otherwise, recur down the tree
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    // Return the unchanged node pointer
    return root;
}

// Function to print the inorder traversal of BST
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        
printf("%d ", root->data);
        
        inorderTraversal(root->left);
        
        inorderTraversal(root->right);
        
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int values[] = { 10,6,8,9,5,41 };

    // Inserting elements into the binary search tree
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
        root = insertNode(root, values[i]);

    // Print the inorder traversal of BST
    printf("Inorder traversal: ");
    inorderTraversal(root);

    return 0;
}



