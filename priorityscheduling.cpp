//Priority Scheduling with Preemptive Algorithm:

#include <stdio.h>
#include <limits.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main() {
    int n, i, current_time = 0, completed_processes = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    printf("Enter process ID, arrival time, burst time, and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d %d", &proc[i].pid, &proc[i].arrival_time, &proc[i].burst_time, &proc[i].priority);
        proc[i].remaining_burst_time = proc[i].burst_time;
    }

    while (completed_processes < n) {
        int highest_priority = INT_MAX;
        int selected_process = -1;

        for (i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].remaining_burst_time > 0 && proc[i].priority < highest_priority) {
                highest_priority = proc[i].priority;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            current_time++;
            continue;
        }

        proc[selected_process].remaining_burst_time--;
        current_time++;

        if (proc[selected_process].remaining_burst_time == 0) {
            completed_processes++;
            proc[selected_process].completion_time = current_time;
            proc[selected_process].turn_around_time = proc[selected_process].completion_time - proc[selected_process].arrival_time;
            proc[selected_process].waiting_time = proc[selected_process].turn_around_time - proc[selected_process].burst_time;
        }
    }

    float avg_tat = 0, avg_wt = 0;
    for (i = 0; i < n; i++) {
        avg_tat += proc[i].turn_around_time;
        avg_wt += proc[i].waiting_time;
    }
    avg_tat /= n;
    avg_wt /= n;

    printf("Process ID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].priority,
               proc[i].completion_time, proc[i].turn_around_time, proc[i].waiting_time);
    }

    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
