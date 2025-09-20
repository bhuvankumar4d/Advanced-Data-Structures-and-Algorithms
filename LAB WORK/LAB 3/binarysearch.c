#include <stdio.h>

int recursiveBinarySearch(int arr[],int low,int high,int key){
    
    if(low>high){
        return -1;
    }
    
    int mid=(low+high)/2;
    
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return recursiveBinarySearch(arr,low,mid-1,key);
    }
    else{
        return recursiveBinarySearch(arr,mid+1,high,key);
    }
}

int iterativeBinarySearch(int arr[],int n,int key){
    
    int low=0,high=n-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]==key) {
            return mid;
        }
        else if(arr[mid]>key) {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    return -1;
}

int main(){

    int n, key, choice, result;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    printf("\nChoose search method:\n");
    printf("1. Recursive Binary Search\n");
    printf("2. Iterative Binary Search\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        result = recursiveBinarySearch(arr, 0, n - 1, key);
    } 
    else {
        result = iterativeBinarySearch(arr, n, key);
    }
    
    if (result != -1) {
        printf("Key %d found at index %d\n", key, result);
    } 
    else {
        printf("Key %d not found\n", key);
    }
    return 0;
}