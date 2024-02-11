#include <stdio.h>

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int bubbleSorting(int a[], int n)
{
    int temp, s = 0, c = 0;
    printf("Bubble Sort is running...\n");

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                s++;
            }
            c++;
        }
    }
    printf("Sorted array by Bubble Sort method is : ");
    printArray(a, n);
    printf("\n");
    printf("Number of swaping is : %d ", s);
    printf("\n");
    printf("Number of comparison is : %d ", c);
    printf("\n");
    return *a;
}

void selectionSorting(int a[], int n)
{
    int indexOfMin, temp, s = 0, c = 0;
    printf("Selection Sort is running...\n");
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexOfMin])
            {
                indexOfMin = j;
            }
            c++;
        }
        // Swap A[i] and A[indexOfMin]
        temp = a[i];
        a[i] = a[indexOfMin];
        a[indexOfMin] = temp;
        s++;
    }
    printf("Sorted array by Selection Sort method is : ");
    printArray(a, n);
    printf("\n");
    printf("Number of swaping is : %d ", s);
    printf("\n");
    printf("Number of comparison is : %d ", c);
    printf("\n");
   // return a;
}

void linearSearching(int *a, int n, int value)
{
    int i, found = 0, s = 0, c = 0;
    printf("\n");
    printf("Linear Search is runnning...\n");
    for (int i = 0; i < n; i++)
    {
        if (value == a[i])
        {
            printf("Given value %d is found in array at the index %d ", value, i + 1);
            c = i;
            printf("\n");
            printf("Number of comparison is : %d ", c + 1);
            printf("\n");
            break;
        }
        else
        {
            found++;
        }
    }

    if (found == n)
    {
        printf("Value is not found in the array\n");
        printf("Number of comparison is : %d ", n);
        printf("\n");
    }
}

int binarySearching(int *a, int n, int value)
{
    int low, mid, high;
    int c = 0;
    printf("Binary Search is runnning...\n");
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == value)
        {
            c++;
            printf("Given value %d is found in array at the index %d\n", a[mid], mid + 1);
            printf("Number of comparison is : %d", c);
            return mid;

            // break;
        }
        if (a[mid] < value)
        {
            low = mid + 1;
            c++;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
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

    int value;
    printf("Given array is : ");
    printArray(arr, num);
    printf("\n");
    printf("\n");

    bubbleSorting(arr, num);
    printf("\n");

    selectionSorting(arr, num);

    printf("\nEnter the value that you want to find : ");
    scanf("%d", &value);

    linearSearching(arr, num, value);
    printf("\n");

   int x = binarySearching(arr, num, value);
    if (x == -1)
    {
        printf("Value is not found in the array");
    }
    printf("\n");

    return 0;
}