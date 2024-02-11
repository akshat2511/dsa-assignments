#include<stdio.h>

int main(){
    int arr[4][4];
    int sub[2][2];
    
    printf("Enter 1 matrix :-\n");
    for(int i=0 ; i<4 ; i++){
        for(int j=0; j<4 ;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter 2 matrix :-\n");
    for(int i=0 ; i<2 ; i++){
        for(int j=0; j<2 ;j++){
            scanf("%d",&sub[i][j]);
        }
    }
    int check=0;
    for(int i=0 ; i<=2 ; i++){
        for(int j=0 ; j<=2; j++){
            if(arr[i][j]==sub[0][0] && arr[i][j+1]==sub[0][1] && arr[i+1][j]==sub[1][0] && arr[i+1][j+1]==sub[1][1]){
                printf("Yes\n");
                printf("Occurence of sub-matrix start at indx : %d,%d\n\n",i,j);
                check=1;
                break;
            }
        }
    }
    if(check==0){
        printf("NO\n\n");
    }

    int i1,j1,i2,j2;
    
    printf("Enter starting indx of 1st sub-matrix : ");
    scanf("%d %d",&i1,&j1);
    printf("Enter starting indx of 2st sub-matrix : ");
    scanf("%d %d",&i2,&j2);
    if(i1>2 || i2>2 || j1>2 || j2>2){
        printf("Invalid indx\n");
    }
    int a[2][2],b[2][2],c[2][2];
    for(int i=0 ; i<=2 ; i++){
        for(int j=0 ; j<=2; j++){
            if(i==i1 && j==j1){
                a[0][0]=arr[i][j];
                a[0][1]=arr[i][j+1];
                a[1][0]=arr[i+1][j];
                a[1][1]=arr[i+1][j+1];
            }
            if(i==i2 && j==j2){
                b[0][0]=arr[i][j];
                b[0][1]=arr[i][j+1];
                b[1][0]=arr[i+1][j];
                b[1][1]=arr[i+1][j+1];
            }
        }
    }

    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<2 ; j++){
            c[i][j] = a[i][j]+b[i][j];
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

}