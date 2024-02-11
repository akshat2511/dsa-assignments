#include<stdio.h>


int main(){


    char var='A';
    char* ptr;
    ptr=&var;


    for(int i=0;i<27;i++){
        printf("%c",*ptr+i);
        
    }printf("\n");
     char var1='a';
    char* ptr2;
    ptr2=&var1;


    for(int i=0;i<27;i++){
        printf("%c",*ptr2+i);
        
    }


    return 0;


}
