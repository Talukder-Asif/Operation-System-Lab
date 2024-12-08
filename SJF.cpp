#include <iostream>
using namespace std;

int main()
{
    int n, i, j, TA = 0, WT = 0;
    float total_TA = 0, total_WT = 0;

    cout << "Enter the number of Process : ";
    cin >> n;

    int Burst[n], Process[n];

    for (i = 0; i < n; i++)
    {
        cout << "Enter the Burst time of process " << i + 1 << " : ";
        cin >> Burst[i];
        Process[i] = i + 1;
    }

    // Bubble Sort Based on Burst Time
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Burst[i] > Burst[j])
            {
                int temp = Burst[i];
                Burst[i] = Burst[j];
                Burst[j] = temp;

                temp = Process[i];
                Process[i] = Process[j];
                Process[j] = temp;
            }
        }
    }

    // Display Table and Calculate Waiting Time and Turnaround Time
    cout << "Process \t Burst Time \t Turnaround Time \tWaiting Time\n";
    cout << "-----------------------------------------------------------------------\n";

    for (i = 0; i < n; i++)
    {
        TA = TA + Burst[i];
        WT = TA - Burst[i];
        total_TA += TA;
        total_WT += WT;

        cout << "P" << Process[i] << "\t\t     " << Burst[i] << "\t\t\t" << TA << "\t\t\t" << WT << endl;
    }

    // Calculate and display averages
    float avg_TA = total_TA / n;
    float avg_WT = total_WT / n;

    cout << "-----------------------------------------------------------------------\n";
    cout << "Average Turnaround Time: " << avg_TA << endl;
    cout << "Average Waiting Time: " << avg_WT << endl;

    return 0;
}
