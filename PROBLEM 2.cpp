#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id, deadline, profit;
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    // Sort jobs by profit in descending order
    sort(arr, arr + n, compare);

    vector<int> result(2, 0);
    vector<bool> slot(n, false); // Array to track available slots

    int count = 0, totalProfit = 0;

    // Iterate through sorted jobs
    for (int i = 0; i < n; i++) {
        // Find the latest available slot before deadline
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                // If slot is available, mark it as occupied
                slot[j] = true;
                // Add profit of the job to total profit
                totalProfit += arr[i].profit;
                // Increment job count
                count++;
                break;
            }
        }
    }

    result[0] = count;
    result[1] = totalProfit;

    return result;
}

int main() {
    int N1 = 4;
    Job jobs1[N1] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    vector<int> result1 = JobScheduling(jobs1, N1);
    cout << result1[0] << " " << result1[1] << endl;

    int N2 = 5;
    Job jobs2[N2] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    vector<int> result2 = JobScheduling(jobs2, N2);
    cout << result2[0] << " " << result2[1] << endl;

    return 0;
}
