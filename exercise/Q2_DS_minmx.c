#include <stdio.h>
#include <conio.h>



void main()
{
    //printf("Enter elements of array: ") ;
    int arr[] = {10, 7, 254, 900, 0, 5, 199};
    int n = sizeof(arr)/sizeof(arr[0]);
    qSort(arr, 0, n-1);
    printf("Sorted array: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nMax ele:%d ",arr[n-1]);
    printf("\nMin ele:%d ",arr[0]);
}

void qSort(int arr[], int lo, int hi)
{
    if(lo<hi)
    {
        int pi = midele(arr,lo,hi) ;
        qSort(arr, pi+1, hi) ;
        qSort(arr, lo, pi-1) ;
    }
}

int midele(int arr[], int lo, int hi)
{
    int pivot = arr[hi];    // pivot
    int i = (lo - 1);  // Index of smaller element

    for (int j = lo; j <= hi- 1; j++)
    {
        if (arr[j] <= pivot)     // If current element is smaller than or
        {                        // equal to pivot
            i++;                 // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[hi]) ;
    return (i + 1);
}

void swap(int* a, int* b)
{
    int t = *a ;
    *a = *b ;
    *b = t ;
}
