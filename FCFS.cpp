#include <iostream>
using namespace std;

int main()
{
    int n, tr = 0, wt = 0;
    float total_wt = 0, total_tr = 0; // Variables for total waiting and turnaround times
    cout << "Enter How Many Process : ";
    cin >> n;
    int Burst[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Burst time for P" << i + 1 << " : ";
        cin >> Burst[i];
    }

    cout << "Process \t Burst Time \t Turnaround Time \tWaiting Time\n";
    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        tr = tr + Burst[i];
        wt = tr - Burst[i];
        total_tr += tr;  // Accumulate turnaround time
        total_wt += wt;  // Accumulate waiting time
        cout << "P" << i + 1 << "\t\t     " << Burst[i] << "\t\t\t" << tr << "\t\t\t" << wt << endl;
    }

    // Calculate and display average times
    float avg_tr = total_tr / n;
    float avg_wt = total_wt / n;

    cout << "-----------------------------------------------------------------------\n";
    cout << "Average Turnaround Time: " << avg_tr << endl;
    cout << "Average Waiting Time: " << avg_wt << endl;

    return 0;
}
