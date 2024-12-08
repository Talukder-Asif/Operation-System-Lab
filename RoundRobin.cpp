#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Process
{
    int id;
    int AT;
    int BT;
    int RM_BT;
    int TAT;
};

// Function to check if a process is already in the queue
bool isInQueue(queue<int> readyQueue, int processIndex)
{
    while (!readyQueue.empty())
    {
        if (readyQueue.front() == processIndex)
            return true;
        readyQueue.pop();
    }
    return false;
}

int main()
{
    int n, QT, currentTime = 0;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    queue<int> readyQueue;

    // Input process details
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter P" << processes[i].id << "'s Arrival Time and Burst Time: ";
        cin >> processes[i].AT >> processes[i].BT;
        processes[i].RM_BT = processes[i].BT; // Initialize Remaining Burst Time
        processes[i].TAT = 0;                 // Initialize Turnaround Time
    }

    cout << "Enter Quantum Time: ";
    cin >> QT;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].AT > processes[j + 1].AT)
            {
                // Swap the two Process objects
                swap(processes[j], processes[j + 1]);
            }
        }
    }

    // Add the first process to the queue when it arrives
    int processCount = 0;
    if (processes[0].AT == 0)
    {
        readyQueue.push(0);
    }
    else
    {
        currentTime = processes[0].AT;
        readyQueue.push(0);
    }

    // Main Round Robin Logic
    while (!readyQueue.empty())
    {
        int idx = readyQueue.front();
        readyQueue.pop();

        // Execute the process for Quantum Time or Remaining Burst Time
        int executionTime = min(QT, processes[idx].RM_BT);
        processes[idx].RM_BT -= executionTime;
        currentTime += executionTime;

        // Check for newly arrived processes and add them to the queue
        for (int i = 0; i < n; i++)
        {
            if (i != idx && processes[i].RM_BT > 0 && processes[i].AT <= currentTime &&
                !isInQueue(readyQueue, i))
            {
                readyQueue.push(i);
            }
        }

        // If the process is not completed, add it back to the queue
        if (processes[idx].RM_BT > 0)
        {
            readyQueue.push(idx);
        }
        else
        {
            // Calculate Turnaround Time for completed process
            processes[idx].TAT = currentTime - processes[idx].AT;
        }

        // Handle idle CPU time
        if (readyQueue.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (processes[i].RM_BT > 0)
                {
                    currentTime = max(currentTime, processes[i].AT);
                    readyQueue.push(i);
                    break;
                }
            }
        }
    }

    // Output Results
    cout << "Process\t\tArrival Time\tBurst Time\tTurnaround Time\t\tWaiting Time\n";

    cout << "----------------------------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        int wt = processes[i].TAT - processes[i].BT; // Waiting Time
        cout << "P" << processes[i].id << "\t\t" << processes[i].AT << "\t\t" << processes[i].BT
             << "\t\t" << processes[i].TAT << "\t\t\t" << wt << "\n";
    }

    return 0;
}
