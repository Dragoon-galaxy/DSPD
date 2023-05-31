#include<stdio.h>
int main()
 {                     //SELECTION SORT
    int n,i,j,temp,min;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements : \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        int min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("Sorted array is ascending order is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}