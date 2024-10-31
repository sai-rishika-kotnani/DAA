#include <stdio.h>
#define MAX_TASKS 10
struct Task {
    int taskID;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};
void calculateTimes(struct Task tasks[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < tasks[i].arrivalTime)
            currentTime = tasks[i].arrivalTime;
        tasks[i].completionTime = currentTime + tasks[i].burstTime;
        tasks[i].turnaroundTime = tasks[i].completionTime - tasks[i].arrivalTime;
        tasks[i].waitingTime = tasks[i].turnaroundTime - tasks[i].burstTime;
        currentTime = tasks[i].completionTime;
    }
}
void displaySchedule(struct Task tasks[], int n) {
    printf("TaskID  Arrival Time  Burst Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-7d%-14d%-12d%-17d%-17d%-13d\n", tasks[i].taskID, tasks[i].arrivalTime, tasks[i].burstTime,
               tasks[i].completionTime, tasks[i].turnaroundTime, tasks[i].waitingTime);
    }
}
int main() {
    int n;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    struct Task tasks[MAX_TASKS];
    printf("Enter arrival time and burst time for each task:\n");
    for (int i = 0; i < n; i++) {
        tasks[i].taskID = i + 1;
        printf("Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].arrivalTime, &tasks[i].burstTime);
    }
    calculateTimes(tasks, n);
    printf("\nFCFS Scheduling:\n");
    displaySchedule(tasks, n);
    return 0;
}

