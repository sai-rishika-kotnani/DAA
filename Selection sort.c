#include<stdio.h>
void swap(int *a, int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int arr[], int n) {
    int i,j,min;
    for (i=0;i<n-1;i++) {
        min=i;
        for (j=i+1;j<n;j++) {
            if (arr[j]<arr[min]) {
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
void printArray(int arr[],int k) {
	int i;
    for (i=0;i<k;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter the num of elements: ");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter %d elements:\n", n);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array: \n");
    printArray(arr,n);
    selectionSort(arr,n);
    printf("Sorted array: \n");
    printArray(arr,n);
    return 0;
}
