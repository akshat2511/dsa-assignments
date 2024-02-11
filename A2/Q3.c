#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    int roll_no;
    char name[15];
    float cgpa;
};
int main(){
    struct student *s;
    int i,n;
    char temp;
    printf("Enter number of students: ");
    scanf("%d",&n);
    s = (struct student *)malloc(n*sizeof(struct student));
    printf("\n\n");
    for ( i = 0; i < n; i++)
    {
        printf("Student %d :\n",i+1);
        printf("Roll number : ");
        scanf("%d",&s[i].roll_no);
        scanf("%c",&temp);
        printf("Enter your name : ");
        gets(s[i].name);
        printf("Enter your CGPA : ");
        scanf("%f",&s[i].cgpa);
        scanf("%c",&temp);
        printf("\n");
    }
    printf("************Here are your details:\n");
    for ( i = 0; i < n; i++)
    {
        printf("Student %d :\n",i+1);
        printf("Roll number : %d\n",s[i].roll_no);
        printf("Name : %s\n",s[i].name);
        printf("CGPA : %.1f\n",s[i].cgpa);
        printf("\n");
    }


    return 0;
}
