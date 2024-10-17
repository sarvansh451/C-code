
#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main() {
    int n, i, j;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    printf("Enter process ID, arrival time, and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].arrival_time, &proc[i].burst_time);
    }

    // Sort processes by burst time for SJF
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                struct process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    proc[0].completion_time = proc[0].arrival_time + proc[0].burst_time;
    proc[0].turn_around_time = proc[0].completion_time - proc[0].arrival_time;
    proc[0].waiting_time = proc[0].turn_around_time - proc[0].burst_time;

    // Calculate completion time, turnaround time, and waiting time for remaining processes
    for (i = 1; i < n; i++) {
        proc[i].completion_time = proc[i - 1].completion_time + proc[i].burst_time;
        proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
    }

    // Calculate average turnaround time and average waiting time
    for (i = 0; i < n; i++) {
        avg_tat += proc[i].turn_around_time;
        avg_wt += proc[i].waiting_time;
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].completion_time,
               proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
