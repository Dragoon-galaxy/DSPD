#include <stdio.h>
int main(){
    int n,i,t;
    printf("Enter the array limit: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the array element to be found: ");
    scanf("%d",&t);
    for(i=0;i<n;i++){
        if (arr[i]==t){
            printf("Element found at index %d and at position %d.",i,i+1);
            break;
        }
    }
    return 0;
}

