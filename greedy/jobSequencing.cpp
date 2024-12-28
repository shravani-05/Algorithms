#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;       // Job ID
    int deadline; // Job deadline
    int profit;   // Job profit
};

void jobSequencing(vector<Job> &jobs, int maxDeadline) {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), [] (const Job& a, const Job& b){
        return a.profit > b.profit;
    });

    // To track available slots and scheduled jobs
    vector<int> result(maxDeadline, -1); // Initialize with -1 (unoccupied)
    int totalProfit = 0;

    // Schedule jobs
    for (const auto &job : jobs) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; j--) {
            if (result[j] == -1) { // Slot is free
                result[j] = job.id; // Schedule the job
                totalProfit += job.profit;
                break;
            }
        }
    }

    // Display the scheduled jobs and total profit
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != -1) {
            cout << result[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    // List of jobs (id, deadline, profit)
    vector<Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    
    // Find the maximum deadline to limit scheduling slots
    int maxDeadline = 0;
    for (const auto &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Call the job sequencing function
    jobSequencing(jobs, maxDeadline);

    return 0;
}
