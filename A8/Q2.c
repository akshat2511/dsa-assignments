#include <stdio.h>
#include <string.h>
int searchVal,searchVal2;
struct student
{
    int regno;
    char name[20];
    char branch[10];
    float cgpa;
} ;
int linearsearch(struct student s[], int reg,int x)
{
    for (int i = 0; i < 3; i++)
    {
        if (s[i].regno == reg)
        {
            printf("Registration Number:%d\n", s[i].regno);
            printf("Name of student:%s\n", s[i].name);
            printf("Branch:%s\n", s[i].branch);
            printf("CGPA IS: %f\n", s[i].cgpa);
            return 0;
        }
    }
    return -1;

}
int binarysearch(struct student s[], int value,int x)
{
     int low, mid, high;
    low = 0;
    high = x-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].regno == value)
        {
        printf("Registration Number:%d\n", s[mid].regno);
            printf("Name of student:%s\n", s[mid].name);
            printf("Branch:%s\n", s[mid].branch);
            printf("CGPA IS: %f\n", s[mid].cgpa);
            
            
            return mid;

        }
        if (s[mid].regno < value)
        {
            low = mid + 1;
    
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;

}

void BubbleSort(struct student s[], int x)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (s[i].regno > s[j].regno)
            {
                int temp = s[i].regno;
                s[i].regno = s[j].regno;
                s[j].regno = temp;
            }
        }
    }
}
void print(struct student s[],int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("Registration Number:%d\n", s[i].regno);
        printf("Name:%s\n", s[i].name);
        printf("Branch:%s\n", s[i].branch);
        printf("CGPA:%f\n", s[i].cgpa);
        printf("\n");
    }
}
int main(){int x;
printf("enter the no of students:");
        scanf("%d", &x);
        struct student s[x];





    for (int i = 0; i < x; i++)
    {
        printf("Enter the registration number: ");
        scanf("%d", &s[i].regno);
        printf("Enter the name: ");
        scanf("%s", &s[i].name);
        printf("Enter the branch: ");
        scanf("%s", &s[i].branch);
        printf("Enter the cgpa: ");
        scanf("%f", &s[i].cgpa);
    }
    printf("\n");
    print(s,x);
    printf("\n");
    printf("Enter search registry no:");
    scanf("%d", &searchVal);
    printf("The search result for linear search is:\n");
    if (linearsearch(s, searchVal,x) == -1)
    {
        printf("Search not found");
    }
    BubbleSort(s,x);
    printf("-----------------------------------------------------------------------------------------------------------\n");
    print(s,x);
    printf("<BINARY SEARCH>Enter search registry no:");
    scanf("%d", &searchVal2);
    printf("The search result for binary search is:\n");
    if (binarysearch(s, searchVal2,x) == -1)
    {
        printf("Search not found");
    }
    return 0;
}