#include <stdio.h>

void swap(int[],int,int);

int partition(int[],int,int);

void quicksort(int[],int,int);

int main(){
    int arr[] = {4,2,5,3,1};
    int len = sizeof(arr) / sizeof(int);
    printf("unsorted array:\n");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("sorted array:\n");
    quicksort(arr,0,len-1);
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int arr[],int i,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for( int j = low;j < high ; j++ ){
        if( arr[j] <= pivot ){
            i = i + 1;
            swap(arr,i,j);
        }
    }
    swap(arr,i + 1,high);
    return i + 1;
}

void quicksort(int arr[] ,int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
