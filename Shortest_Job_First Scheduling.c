#include <stdio.h>
struct SJFF
{
    int id;
    int burst;
    int arrival;
};

void swap(struct SJFF *A, struct SJFF *B)
{
    struct SJFF temp = *A;
    *A = *B;
    *B = temp;
}

int main()
{
    int NOP;
    printf("Enter the number of processes: ");
    scanf("%d", &NOP);
    printf("\n");
    struct SJFF obj[NOP];
    for (int i = 0; i < NOP; i++)
    {
        obj[i].id = i;
        printf("Enter the details of process: %d\n", obj[i].id);
        printf("Enter the arrival Time: ");
        scanf("%d", &obj[i].arrival);
        printf("Enter the burst time: ");
        scanf("%d", &obj[i].burst);
        printf("\n");
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
    while (NOP != 0)
    {
        if (time < obj[0].arrival)
        {
            while (time < obj[0].arrival)
                printf("%d\t\tWaited\n", time++);
        }

        if (obj[currentProcess].burst != 0)
        {
            while (obj[currentProcess].burst > 0)
            {
                printf("%d\t\tP[%d]\n", time++, obj[currentProcess].id);
                obj[currentProcess].burst--;
            }
        }
        if (currentProcess == NOP - 1)
            NOP--;
        else
        {
            for (int i = 0; i < NOP; i++)
            {
                obj[i].id = obj[i + 1].id; 
                obj[i].burst = obj[i + 1].burst;
                obj[i].arrival = obj[i + 1].arrival; 
            }
            NOP--;
        }

        if (time >= obj[NOP - 1].arrival)
        {
            int min = 0;
            for (int i = 0; i < NOP; i++)
            {
                if (obj[i].burst < obj[min].burst)
                    min = i;
            }
            currentProcess = min;
        }
    }
}

