#include <stdio.h>
struct SRTF
{
    int id;
    int burst;
    int arrival;
    int complete;
};

void swap(struct SRTF *A, struct SRTF *B)
{
    struct SRTF temp = *A;
    *A = *B;
    *B = temp;
}

int main()
{
    int NOP;
    int sumBurst = 0;
    int burstCounter = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &NOP);
    struct SRTF obj[NOP];
    for (int i = 0; i < NOP; i++)
    {
        obj[i].id = i;
        printf("Enter the details of process: %d\n", obj[i].id);
        printf("Enter the arrival Time: ");
        scanf("%d", &obj[i].arrival);
        printf("Enter the burst time: ");
        scanf("%d", &obj[i].burst);
        sumBurst += obj[i].burst;
        obj[i].complete = 0;
    }

    for (int i = 0; i < NOP - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < NOP; j++)
        {
            if (obj[min].arrival > obj[j].arrival)
            {
                min = j;
            }
        }

        swap(&obj[i], &obj[min]);
    }

    int currentProcess = 0;
    int time = 1;
    printf("Time\t\tProcess\n");
    int timecounter = 1;
    while (burstCounter < sumBurst)
    {
        if (obj[currentProcess].burst != 0)
        {
            printf("%d\t\tP[%d]\n", time++, obj[currentProcess].id);
            burstCounter++;
            timecounter++;
            obj[currentProcess].burst--;
        }
        if (timecounter >= obj[currentProcess + 1].arrival && currentProcess != NOP - 1)
        {
            if (obj[currentProcess].burst > obj[currentProcess + 1].burst && obj[currentProcess + 1].complete == 0)
                currentProcess += 1;
        }
        else
        {
            timecounter++;
        }
        if (obj[currentProcess].burst == 0)
        {
            obj[currentProcess].complete = 1;
        }

        if (timecounter >= obj[NOP - 1].arrival && obj[currentProcess].complete == 1)
        {
            int min;
            for (int i = 0; i < NOP; i++)
            {
                if (obj[i].burst != 0)
                {
                    min = i;
                }
            }
            for (int i = 0; i < NOP; i++)
            {
                if (obj[i].burst < obj[min].burst && obj[i].complete == 0 && obj[min].complete == 0)
                    min = i;
            }
            currentProcess = min;
        }
    }
}
