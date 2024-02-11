#include<stdio.h>
struct result{
    float avg,percent;
};
struct result func(int m1, int m2, int m3){
    struct result var;
    var.avg = (m1+m2+m3)/3;
    var.percent = (m1+m2+m3)/3;
    return var;
}
int main(){
    int m1,m2,m3;
    printf("Enter marks of subject 1 : ");
    scanf("%d",&m1);
    printf("Enter marks of subject 2 : ");
    scanf("%d",&m2);
    printf("Enter marks of subject 3 : ");
    scanf("%d",&m3);
    struct result final = func(m1,m2,m3);
    printf("Average = %f\n",final.avg);
    printf("Percentage = %f",final.percent);


    return 0;
}
