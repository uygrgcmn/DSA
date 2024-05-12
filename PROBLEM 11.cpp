#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool isPossible(const vector<int>& pages, int n, int m, int mid) {
    int students = 1;
    int pagesAllocated = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > mid) {
            return false;
        }
        if (pagesAllocated + pages[i] > mid) {
            students++;
            pagesAllocated = pages[i];
            if (students > m) {
                return false;
            }
        }
        else {
            pagesAllocated += pages[i];
        }
    }
    return true;
}

int findPages(int N, int M, vector<int>& A) {
    int totalPages = accumulate(A.begin(), A.end(), 0);
    int maxPages = *max_element(A.begin(), A.end());

    int low = maxPages;
    int high = totalPages;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N1 = 4, M1 = 2;
    vector<int> A1 = { 12, 34, 67, 90 };
    cout << findPages(N1, M1, A1) << endl; // Output: 113

    int N2 = 3, M2 = 2;
    vector<int> A2 = { 15, 17, 20 };
    cout << findPages(N2, M2, A2) << endl; // Output: 32

    return 0;
}
