#include <iostream>
using namespace std;

int itemCount;
int time_quantum;
int *remTime;
int *arrivalTime;
int *proc;
int size;

void shift()
{
    int temp = proc[0];
    int temp1 = remTime[0];
    for (int i = 0; i < itemCount; i++)
    {
        proc[i] = proc[i + 1];       // move all element to the left except first one
        remTime[i] = remTime[i + 1]; // move all element to the left except first one
    }

    proc[itemCount - 1] = temp;
    remTime[itemCount - 1] = temp1;
}

void display(int n)
{
    for (int i = 0; i < n; i++)
        cout << proc[i] << " ";
}

int main()
{
    cout << "Enter the number of Processes: ";
    cin >> itemCount;
    remTime = new int[itemCount];
    arrivalTime = new int[itemCount];
    proc = new int[itemCount];
    cout << "Enter the Time Quantum: ";
    cin >> time_quantum;
    for (int i = 0; i < itemCount; i++)
    {
        cout << "Enter the details of process " << i + 1 << endl;
        cout << "Enter the arrival time: ";
        cin >> arrivalTime[i];
        cout << "Enter the burst time: ";
        cin >> remTime[i];
    }

    for (int i = 0; i < itemCount; i++)
    {
        proc[i] = i;
    }
    int time = 1;
    cout << "Time\t\tProcess\n";
    int k = 0;
    int flag = 1;
    int i = 0;
    while (itemCount != 0)
    {
        for (i = 0; i < time_quantum; i++)
        {   int toq = proc[0];
            if (remTime[0] > 0)
            {
                cout << time++ << "\t\t"
                     << "P[" << toq << "]" << endl;
                remTime[0]--;
            }
        }
        if (remTime[0] > 0)
        {
            shift();
        }
        else
        {   shift();
            itemCount--;
        }
    }
}
