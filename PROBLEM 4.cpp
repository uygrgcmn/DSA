#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a pair of numbers
struct Pair {
    int first, second;
};

// Comparator function to sort pairs based on the second number
bool compare(Pair a, Pair b) {
    return a.second < b.second;
}

int maxChainLen(Pair arr[], int n) {
    // Sort pairs based on the second number in each pair
    sort(arr, arr + n, compare);

    int maxChainLength = 1;
    int prevEnd = arr[0].second;

    // Iterate through sorted pairs, greedily select pairs forming a valid chain
    for (int i = 1; i < n; i++) {
        if (arr[i].first > prevEnd) {
            maxChainLength++;
            prevEnd = arr[i].second;
        }
    }

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
