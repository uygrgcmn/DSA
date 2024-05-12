#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id, deadline, profit;
};

// Comparator function to sort jobs by deadlines in ascending order
bool compare(Job a, Job b) {
    return a.deadline < b.deadline;
}

int maxProfit(Job arr[], int n) {
    // Sort jobs by deadlines in ascending order
    sort(arr, arr + n, compare);

    // Initialize dp array to store maximum profit until each deadline
    vector<int> dp(n, 0);

    // Iterate through sorted jobs
    for (int i = 0; i < n; i++) {
        // Find the latest available slot before deadline for the current job
        int availableSlot = min(n, arr[i].deadline) - 1;

        // Include or exclude the current job and update dp array
        for (int j = availableSlot; j >= 0; j--) {
            if (j == 0) {
                // If availableSlot is 0, the job can be done
                dp[j] = max(dp[j], arr[i].profit);
            }
            else {
                // If availableSlot > 0, find the maximum profit by including or excluding the job
                dp[j] = max(dp[j], max(dp[j - 1] + arr[i].profit, dp[j]));
            }
        }
    }

    // Return the maximum profit that can be obtained
    return dp[n - 1];
}

int main() {
    int N1 = 4;
    Job jobs1[N1] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    cout << maxProfit(jobs1, N1) << endl;

    int N2 = 5;
    Job jobs2[N2] = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15} };
    cout << maxProfit(jobs2, N2) << endl;

    return 0;
}
