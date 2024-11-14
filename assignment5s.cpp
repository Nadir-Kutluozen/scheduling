#include <iostream>

using namespace std;
// we have top create our data type here that has the id , burst time, and spots for the average times 
struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function for FCFS scheduling
void FCFS(Process processes[], int n) { // array created type of process 
    processes[0].waitingTime = 0;  
    processes[0].turnaroundTime = processes[0].burstTime;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function for SJF scheduling
void SJF(Process processes[], int n) {
    //  (shortest job first)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burstTime < processes[i].burstTime) {
                swap(processes[i], processes[j]);
            }
        }
    }
    
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

//toString for the both  scheduling 
void printResults(Process processes[], int n, const string& schedulingType) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    
    cout << "\n----------------- " << schedulingType << " -----------------" << endl;
    cout << "Process ID | Waiting Time | Turnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << endl;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }
    cout << "\n-Average Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "-Average Turnaround Time: " << (float)totalTurnaroundTime / n << endl;
}

int main() {
    // from the question 2 , these are the processes with their burst time
    Process processes[] = {
        {1, 2, 0, 0},
        {2, 1, 0, 0},
        {3, 8, 0, 0},
        {4, 4, 0, 0},
        {5, 5, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    
    // FCFS 
    Process fcfsProcesses[5];
    for (int i = 0; i < n; i++) {
        fcfsProcesses[i] = processes[i];
    }
    FCFS(fcfsProcesses, n);
    printResults(fcfsProcesses, n, "FCFS");

    // SJF  
    Process sjfProcesses[5];
    for (int i = 0; i < n; i++) {
        sjfProcesses[i] = processes[i];
    }
    SJF(sjfProcesses, n);
    printResults(sjfProcesses, n, "SJF");
    
    return 0;
}
