#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;
} *first = NULL;

void create(int n)
{
    int i = 0;
    struct Node *t, *last;
    int A, B;
    for (; i < n; i++)
    {
        printf("enter %dth value (coeff _ power):", i + 1);
        scanf("%d %d", &A, &B);

        if (i == 0)
        {

            first = (struct Node *)malloc(sizeof(struct Node));
            first->coeff = A;
            first->power = B;

            first->next = NULL;
            last = first;
        }

        else
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->coeff = A;
            t->power = B;

            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%dx^%d ", node->coeff, node->power);
        node = node->next;
        if (node != NULL)
        {
            printf("+ ");
        }
    }
    printf("=");
}
int eval(struct Node *node, int x)
{
    int sum=0;
    while (node != NULL)
    {

        sum = sum + (node->coeff) * pow(x, node->power);
        node = node->next;
    }
    return sum;
}

int main()
{
    printf("enter the no. of values:");
    int n;
    scanf("%d", &n);
    printf("enter the value of x:");
    int x;
    scanf("%d", &x);
    create(n);
    printList(first);
    printf("%d", eval(first, x));



  char a;
scanf("%d",a);
}


