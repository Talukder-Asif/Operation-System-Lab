#include <iostream>
using namespace std;
int main (){
    int n, i, j, TA = 0, WT = 0;
    cout << "Enter the number of Process : ";
    cin >> n;

    int Burst[n], Priority[n], Process[n];

    for(i=0; i<n; i++){
        Process[i] = i+1;
        cout << "Enter the Priority and Burst time of process "<< Process[i] <<" : ";
        cin >> Priority[i] >> Burst[i];
    }

    //Bouble Sort Based on Brust Time
    for(i=0; i<n; i++){
        for(j = i+1; j<n; j++){
            if(Priority[i] > Priority[j]){
                int temp = Burst[i];
                Burst[i] = Burst[j];
                Burst[j] = temp;

                temp = Process[i];
                Process[i] = Process[j];
                Process[j] = temp;

                temp = Priority[i];
                Priority[i] = Priority[j];
                Priority[j] = temp;
            }
        }
    }

    //Final touch, Find WT and RA
    cout << "Process \t Priority \t Burst Time \t Turn Arround Time \tWaiting Time\n";
    cout << "--------------------------------------------------------------------------------------\n";
    for(i=0; i<n; i++){
        TA = TA + Burst[i];
        WT = TA - Burst[i];
        cout << "P" << Process[i] << "\t\t  " << Priority[i] <<"\t\t  " <<Burst[i] << "\t\t\t" << TA << "\t\t\t" << WT << endl;
    }

}
