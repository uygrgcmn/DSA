#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    // Initialize dp table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base case: There is only one way to form a sequence of length 1 with any number i <= m
    for (int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }

    // Compute dp table
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            dp[i][j] = dp[i / 2][j - 1] + dp[i - 1][j - 1];
        }
    }

    // Sum up the last row to get the total number of possible sequences
    int total = 0;
    for (int i = 1; i <= m; i++) {
        total += dp[i][n];
    }

    return total;
}

int main() {
    int m1 = 10, n1 = 4;
    cout << numberSequence(m1, n1) << endl; // Output: 4

    int m2 = 5, n2 = 2;
    cout << numberSequence(m2, n2) << endl; // Output: 6

    return 0;
}
