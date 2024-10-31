#include <stdio.h>
#include <limits.h>
int max(int a, int b, int c) {
    return (a > b && a > c) ? a : (b > c) ? b : c;
}
int maxCrossingSubarray(int arr[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}
int maxSubArrayUtil(int arr[], int low, int high) {
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    return max(maxSubArrayUtil(arr, low, mid),
               maxSubArrayUtil(arr, mid + 1, high),
               maxCrossingSubarray(arr, low, mid, high));
}
int maxSubArray(int arr[], int n) {
    return maxSubArrayUtil(arr, 0, n - 1);
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int maxSum = maxSubArray(arr, n);
    printf("Maximum subarray sum is: %d\n", maxSum);
    return 0;
}