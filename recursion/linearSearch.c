#include<stdio.h>

/* Recursive function to search x in arr[l..r] */
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     if (arr[r] == x)
        return r;
     return recSearch(arr, l+1, r-1, x);
}

int main()
{
    int arr[10] = {}, i=0, n;
    printf ("Enter 10 array elements:\n");

    for (i; i<10; n=scanf("%d", &arr[i++]));
    printf ("Enter number to be search in given array: ");
    scanf (" %d", &n);

    int index = recSearch(arr, 0, i, n);
    if (index != -1)
       printf("Element %d is present at index %d.\n", n, index);
    else
        printf("Element %d is not present.\n", n);
    return 0;
}
