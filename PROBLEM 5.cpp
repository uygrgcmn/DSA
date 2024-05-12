#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first, second;
};

// Comparator function to sort pairs based on the first number
bool compare(Pair a, Pair b) {
    return a.first < b.first;
}

int maxChainLen(Pair arr[], int n) {
    // Sort pairs based on the first number in each pair
    sort(arr, arr + n, compare);

    // Initialize DP array to store the length of the longest chain ending at each pair
    vector<int> dp(n, 1);

    // Iterate through pairs and update the DP array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i].first > arr[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in the DP array
    int maxChainLength = *max_element(dp.begin(), dp.end());

    return maxChainLength;
}

int main() {
    int N1 = 5;
    Pair pairs1[N1] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    cout << maxChainLen(pairs1, N1) << endl;

    int N2 = 2;
    Pair pairs2[N2] = { {5, 10}, {1, 11} };
    cout << maxChainLen(pairs2, N2) << endl;

    return 0;
}
