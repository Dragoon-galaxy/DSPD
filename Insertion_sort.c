#include<stdio.h>
int main()
 {                     //INSERTION SORT
    int i,j,n,temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements : \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i = 1;i < n;i++)
    {
        temp = arr[i];
        j = i-1;  
        while (j>=0 && arr[j]> temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    printf("Sorted array in  ascending order is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}