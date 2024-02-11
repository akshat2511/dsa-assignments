#include<stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSorting(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSorting(A, low, mid);
        mergeSorting(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int num;
    printf("Enter the number of elements : ");
    scanf("%d", &num);
    int A[num];
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element no.%d : ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("Given array is : ");
    printArray(A, num);
    printf("\n");

    printf("\n");
    printf("Merge Sort is running...\n");
    printf("Sorted array by Merge Sort method is : ");
    mergeSorting(A, 0, num);
    printArray(A, num);

    return 0;
}