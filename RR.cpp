#include <iostream>
using namespace std;

int main() {
    int n, i, j, QT, temp, count = 0, ex = 0, wt;
    cout << "Enter the number of processes: ";
    cin >> n;

    int PNo[n], AT[n], BT[n], RM_BT[n], TAT[n];

    // Input process details
    for (i = 0; i < n; i++) {
        PNo[i] = i + 1;
        cout << "Enter P" << PNo[i] << "'s Arrival Time and Burst Time: ";
        cin >> AT[i] >> BT[i];
        RM_BT[i] = BT[i]; // Initialize Remaining Burst Time
    }

    cout << "Enter Quantum Time: ";
    cin >> QT;

    // Sort processes by Arrival Time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (AT[i] > AT[j]) {
                // Swap Arrival Time
                temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;

                // Swap Process Number
                temp = PNo[i];
                PNo[i] = PNo[j];
                PNo[j] = temp;

                // Swap Burst Time
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;

                // Swap Remaining Burst Time
                temp = RM_BT[i];
                RM_BT[i] = RM_BT[j];
                RM_BT[j] = temp;
            }
        }
    }

    // Main Round Robin Logic
    int currentTime = 0;
    while (true) {
        for (i = 0, count = 0; i < n; i++) {
            if (RM_BT[i] == 0) {
                count++; // Process completed
                continue;
            }

            // Check if process has arrived
            if (currentTime < AT[i]) {
                currentTime = AT[i]; // Skip to process arrival time
            }

            // Execute process for Quantum Time or Remaining Burst Time
            temp = min(QT, RM_BT[i]);
            RM_BT[i] -= temp;
            currentTime += temp;

            // Update Turnaround Time when process is completed
            if (RM_BT[i] == 0) {
                TAT[i] = currentTime - AT[i];
            }
        }

        // Break when all processes are complete
        if (count == n) {
            break;
        }
    }
}
