#include <stdio.h>
#define MAX_TASKS 10
#define MAX_PROCESSORS 3
int main() {
    int num_tasks, i, j;

    printf("Enter the no of tasks: ");
    scanf("%d", &num_tasks);
    if (num_tasks > MAX_TASKS) {
        printf("Error!!n");
        return 1;
    }
    int adj_matrix[MAX_TASKS][MAX_TASKS];
    for (i = 0; i < num_tasks; i++) {
        for (j = 0; j < num_tasks; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    int num_edges;
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges and weights:\n");
    for (i = 0; i < num_edges; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        if (source < 0 || source >= num_tasks || destination < 0 || destination >= num_tasks) {
            printf("Error: Invalid task indices.\n");
            return 1;
        }
        adj_matrix[source][destination] = weight;
    }
    printf("Adjacency Matrix:\n");
    for (i = 0; i < num_tasks; i++) {
        for (j = 0; j < num_tasks; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
    int wcet_matrix[MAX_TASKS][MAX_PROCESSORS];
    printf("\nEnter the Worst-Case Execution Time (WCET) of each task on different processors:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("Enter WCET of Task %d on Processors (P1, P2, P3): ", i + 1);
        for (j = 0; j < MAX_PROCESSORS; j++) {
            scanf("%d", &wcet_matrix[i][j]);
        }
    }
    printf("\nWCET Matrix:\n");
    for (i = 0; i < num_tasks; i++) {
        for (j = 0; j < MAX_PROCESSORS; j++) {
            printf("%d ", wcet_matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
