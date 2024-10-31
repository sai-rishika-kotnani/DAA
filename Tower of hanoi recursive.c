#include <stdio.h>
void towerOfHanoi(int n,char source,char auxiliary,char destination) {
    if (n==1) {
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    towerOfHanoi(n-1,auxiliary,source,destination);
}
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    if (n<=0) {
        printf("Number of disks should be a positive integer.\n");
        return 1;
    }
    printf("Steps to solve the Towers of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n,'A','B','C');
    return 0;
}
