#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p,n,i;
    printf("Enter number upto which you want lists: ");
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(int));
    printf("Enter elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",p+i);
    }
    printf("You entered: \n");
    for(i=0;i<n;i++){
        printf("%d  ",*(p+i));
    }


    return 0;
}
