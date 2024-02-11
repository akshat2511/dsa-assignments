#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    return 0;
}


/*Code Snippet 4: Implementing isEmpty and  isFull

Since there is no element inside the stack, we can now check if it’s empty.

    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is not empty");
    }
Code Snippet 5: Calling the function isEmpty

Output:

The stack is empty
PS D:\MyData\Business\code playground\Ds & Algo with Notes\Code>
Figure 1: Output of the above program

So, yes, that worked fine. Now, we can easily push some elements inside this stack manually to test this isEmpty function. This should not be a tough job. Just insert an element at top+1 and increment top by 1.

// Pushing an element manually
    s->arr[0] = 7;
    s->top++;
 
    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty");
    }
    else{
        printf("The stack is not empty");
    }
Code Snippet 6: Inserting an element in the stack

Output after inserting an element:

The stack is not empty*/
