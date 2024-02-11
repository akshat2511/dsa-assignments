#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int partition(int A[], int low, int high)
{
    int p = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= p)
        {
            i++;
        }

        while (A[j] > p)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSorting(int A[], int low, int high)
{
    int partitionIndex; 
    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSorting(A, low, partitionIndex - 1); 
        quickSorting(A, partitionIndex + 1, high); 
    }
}

int main()
{
    int num;
    printf("Enter the number of elements : ");
    scanf("%d", &num);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        printf("Enter the element no.%d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Given array is : ");
    printArray(arr, num);
    printf("\n");

    printf("\n");
    printf("Quick Sort is running...\n");
    printf("Sorted array by Quick Sort method is : ");
    quickSorting(arr, 0, num-1);
    printArray(arr, num);
    
    return 0;
}