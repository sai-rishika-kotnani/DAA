#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)b)->value / (double)((struct Item *)b)->weight);
    double ratio2 = (double)(((struct Item *)a)->value / (double)((struct Item *)a)->weight);
    return ratio1 - ratio2;
}


double fractionalKnapsack(int capacity, struct Item items[], int n) {
    
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;


    for (int i = 0; i < n; i++) {
      
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity, n;

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = malloc(n * sizeof(struct Item));

    
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    
    double maxValue = fractionalKnapsack(capacity, items, n);

    printf("The maximum value in the knapsack is: %.2lf\n", maxValue);

    free(items); 

    return 0;
}