#include<stdio.h>
int length(char s[])
{
  int i=0;
for(i=0;s[i]!='\0';i++)
{
    
}
return i-1;
}
char *concat(char s1[],char s2[])
{
	int s11=length(s1);
	int i=s11;
	for(i=s11;i<length(s1)+length(s2);i++)
	{
		s1[i]=s2[i-s11];
	}

}
char  *cpy(char s2[],char s1[])
{
	int s11=length(s1);
	int s22=length(s2);

for(int i=0;i<s11+s22;i++)
{
	if(i<s11)
	s2[i]=s1[i];
	else
	s2[i]='\0';
}
}
int cmp(char s1[],char s2[])
{
	int c;
for(int i=0;i<=length(s1);i++)
{
	if(s1[i]-s2[i]!=0)
	{
		if(s1[i]=='\0')
		s1[i]=10;
		if(s2[i]=='\0')
		s2[i]=10;
		c=s1[i]-s2[i];
        break;
	}
	}
	return c;	
}
void fos(char s1[])
{
	char a;
	printf("enter character to be searched in the string");
	scanf("%s",&a);
	int l=0;
	for(int i=0;i<length(s1);i++)
	{
		l++;
		if(s1[i]==a)
		{
		break;
		}
	}
	if(l==length(s1))
	printf("no %c present in the string",a);
	else
	printf("%c present at %d index",a,l-1);
}
void subs(char s1[])
{
    char s2[50];
    printf("enter string to be checked");
    scanf("%s",s2);
    int l1=length(s1);
    int l2=length(s2);
    int l,c,m=0;
    for(int k=0;k<l1;k++)
    {
                    if(l==l2)
            {
                break;
            }
        for(int i=k;i<l1;i++)
        {
            l=0;
            c=-1;
            for(int j=k;j<=i;j++)
            {
                c++;
            if(s1[j]==s2[c])
            {
                l++;
            }
            }
            if(l==l2)
            {
                m++;
                printf("true");
                break;
            }
        }
        
    }
    if(m==0)
    printf("false");
}
char *rev(char s1[])
{
	char temp;
for(int i=0;i<length(s1)/2;i++)
{

	temp=s1[i];
	s1[i]=s1[length(s1)-i-1];
	s1[length(s1)-i-1]=temp;
	}	
	return s1;
}

char *vcp(char s1[])
{
for(int i=0;i<length(s1);i++)
{

	if(s1[i]=='a'||s1[i]=='A'||s1[i]=='e'||s1[i]=='E'||s1[i]=='i'||s1[i]=='I'||s1[i]=='o'||s1[i]=='O'||s1[i]=='u'||s1[i]=='U')
	s1[i]='*';
	else
	s1[i]='#';
}
return s1;
}
