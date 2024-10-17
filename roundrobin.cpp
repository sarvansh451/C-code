#include <stdio.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_burst_time; // Remaining burst time for the process
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main() {
    int n, i, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    struct process proc[n];

    printf("Enter process ID, arrival time, and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].arrival_time, &proc[i].burst_time);
        proc[i].remaining_burst_time = proc[i].burst_time; // Initialize remaining burst time
    }

    int remaining_processes = n;
    int current_time = 0;

    // Process until all processes are completed
    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (proc[i].remaining_burst_time > 0) {
                // Execute the process for time quantum or remaining burst time, whichever is smaller
                int execute_time = (proc[i].remaining_burst_time > time_quantum) ? time_quantum : proc[i].remaining_burst_time;
                proc[i].remaining_burst_time -= execute_time; // Update remaining burst time

                current_time += execute_time; // Update current time

                if (proc[i].remaining_burst_time == 0) {
                    // Process has completed
                    remaining_processes--;
                    proc[i].completion_time = current_time;
                    proc[i].turn_around_time = proc[i].completion_time - proc[i].arrival_time;
                    proc[i].waiting_time = proc[i].turn_around_time - proc[i].burst_time;
                }
            }
        }
    }

    // Calculate average turnaround time and average waiting time
    float avg_tat = 0, avg_wt = 0;
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
