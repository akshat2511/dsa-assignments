#include<stdio.h>
#include"mystring.h"
int main()
{
char s1[50], s2[50];
int n;
fgets(s1,50,stdin);
fgets(s2,50,stdin);
printf("Enter N=1 For Strlength\n");
printf("Enter N=2 For concat\n");
printf("Enter N=3 For cpy\n");
printf("Enter N=4 For compare\n");
printf("Enter N=5 For first occurence\n");
printf("Enter N=6 For Substring\n");
printf("Enter N=7 For Reverse\n");
printf("Enter N=8 For coversion into * #\n");
scanf("%d",&n);
if(n==1)
{
printf("%d\n",length(s1));
printf("%d\n",length(s2));
}
else if(n==2)
{
concat(s1,s2);
printf("%s",s1);
}
else if(n==3)
{
cpy(s1,s2);
printf("%s",s1);	
}
else if(n==4)
{
	printf("%d",cmp(s1,s2));
}
else if(n==5)
{
	fos(s1);
}
else if(n==6)
{
	subs(s1);
}
else if(n==7)
{
	rev(s1);
printf("%s",s1);
}
else if(n==8){

vcp(s1);
printf("%s",s1);
}
}
