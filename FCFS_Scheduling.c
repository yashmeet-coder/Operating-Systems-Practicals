#include <stdio.h>
int waitTime[20];
int burstTime[20];
int turnAround[20];
int NOP;
int wsum;
int tsum;
void waitingTime()
{
    waitTime[0] = 0;
    for (int i = 1; i <= NOP; i++)
    {
        for (int j = 0; j < i; j++)
            waitTime[i] += burstTime[j];
    }
}

void turnAroundTime()
{
    for (int i = 0; i < NOP; i++)
        turnAround[i] = waitTime[i] + burstTime[i];
}

int main()
{
    printf("Enter the number of processes: ");
    scanf("%d", &NOP);
    for (int i = 0; i < NOP; i++)
    {
        printf("Enter the details of Process %d\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &burstTime[i]);
    }
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    waitingTime();
    turnAroundTime();
    for (int i = 0; i < NOP; i++)
    {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t\n", i + 1, burstTime[i], waitTime[i], turnAround[i]);
    }

    for (int i = 0; i < NOP; i++)
    {
        wsum += waitTime[i];
        tsum += turnAround[i];
    }

    printf("Average waiting time: %d\n", wsum / NOP);
    printf("Average turnaround time: %d", tsum / NOP);
}
