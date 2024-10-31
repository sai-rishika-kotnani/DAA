#include <stdio.h>
#include <stdlib.h>
#define NUM_RODS 3
#define MAX_DISKS 100
char rod[] = {'S', 'A', 'D'};
struct Stack {
    int top;
    int disks[MAX_DISKS];
};
struct Stack stacks[NUM_RODS];
void initStacks() {
	int i;
    for (i = 0; i < NUM_RODS; i++) {
        stacks[i].top = -1;
    }
}
void push(int rodIdx, int disk) {
    stacks[rodIdx].disks[++stacks[rodIdx].top] = disk;
}
int pop(int rodIdx) {
    return stacks[rodIdx].disks[stacks[rodIdx].top--];
}
void moveDisk(int a, int b) {
    if (stacks[b].top == -1 || (stacks[a].top != -1 && stacks[a].disks[stacks[a].top] < stacks[b].disks[stacks[b].top])) {
        printf("Move disk %d from rod %c to rod %c\n", stacks[a].disks[stacks[a].top], rod[a], rod[b]);
        push(b, pop(a));
    } else {
        moveDisk(b, a);
    }
}
void towerOfHanoi(int n) {
    printf("Tower of Hanoi for %d disks:\n", n);
    int src=0,aux=1,dest=2;
    int i;
    for (i=n;i>0;i--) {
        push(src,i);
    }
    int totalMoves=(1<<n)-1;
    if (n % 2 == 0) {
        int temp = aux;
        aux = dest;
        dest = temp;
    }
    for (i = 1; i <= totalMoves; i++) {
        if (i % 3 == 0) {
            moveDisk(aux, dest);
        } else if (i % 3 == 1) {
            moveDisk(src, dest);
        } else {
            moveDisk(src, aux);
        }
    }
}
int main() {
    int n = 3; // number of disks
    initStacks();
    towerOfHanoi(n);
    return 0;
}







