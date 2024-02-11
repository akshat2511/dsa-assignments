// push pop peek isempty tata motors
//  name id age salary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
void pop1(struct Node *A)
{
  struct Node *temp = A;

  free(temp);
  A = A->next;
}
int main()
{
  int id;
  char name[100];
  int age;
  int salary;
  int n;
  struct Node *A = NULL;
  printf("1--ENTER WORKER DETAILS\n2--DISPLAY LIST\n3--DELETE DETAILS\n4--ISEMPTY\n5--PEEK\n6--EXIT\n\n");
  int choice;
  while (choice != 6)
  {
    printf("enter the choice:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      printf("ENTER NAME=");
      scanf("%s", name);
      printf("ENTER AGE=");
      scanf("%d", &age);
      printf("ENTER ID=");
      scanf("%d", &id);
      printf("ENTER salary=");
      scanf("%d", &salary);
      push(&A, id, name, age, salary);
      break;
    }
    case 2:
    {
      display(A);
      break;
    }
    case 3:
    {
      pop(&A);

      break;
    }
    case 4:
    {
      isempty(A);
      break;
    }
    case 5:
    {
      peek(A);
      break;
    }
    case 6:
      printf("Exiting the program.\n");
      break;
    default:
      printf("Invalid choice! Please enter a valid option.\n");
      break;
    }
  }
char a;
scanf("%d",a);
  return 0;
}
