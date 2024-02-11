#include<stdio.h>
#include<stdlib.h>
int main(){
    char *str;
    int n,vowel=0,consonant=0;
    printf("Enter length of string: ");
    scanf("%d",&n);
    str = (char *)malloc(n*sizeof(char));
    printf("String : ");
    scanf("%s",str);
    int i;
    for(i=0;i<n;i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            vowel++;
        else
            consonant++;
    }
    printf("\nVowels : %d\nConsonants : %d",vowel,consonant);


    return 0;
}
