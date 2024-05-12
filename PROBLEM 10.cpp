#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthElementUtil(const vector<int>& arr1, int start1, int end1, const vector<int>& arr2, int start2, int end2, int k) {
    // If arr1 is empty, return kth element of arr2
    if (start1 > end1) {
        return arr2[start2 + k - 1];
    }
    // If arr2 is empty, return kth element of arr1
    if (start2 > end2) {
        return arr1[start1 + k - 1];
    }
    // Base case: If k becomes 1, return minimum of first elements of arr1 and arr2
    if (k == 1) {
        return min(arr1[start1], arr2[start2]);
    }

    // Find the mid points of both arrays
    int mid1 = start1 + (end1 - start1) / 2;
    int mid2 = start2 + (end2 - start2) / 2;

    // If k/2-th element in arr1 is smaller than k/2-th element in arr2
    if (arr1[mid1] < arr2[mid2]) {
        // Discard first half of arr1 and update k
        return kthElementUtil(arr1, mid1 + 1, end1, arr2, start2, end2, k - (mid1 - start1 + 1));
    }
    else {
        // Discard first half of arr2 and update k
        return kthElementUtil(arr1, start1, end1, arr2, mid2 + 1, end2, k - (mid2 - start2 + 1));
    }
}

int kthElement(const vector<int>& arr1, const vector<int>& arr2, int k) {
    // Call the utility function with appropriate start and end indices of both arrays
    return kthElementUtil(arr1, 0, arr1.size() - 1, arr2, 0, arr2.size() - 1, k);
}

int main() {
    vector<int> arr1 = { 2, 3, 6, 7, 9 };
    vector<int> arr2 = { 1, 4, 8, 10 };
    int k1 = 5;
    cout << kthElement(arr1, arr2, k1) << endl; // Output: 6

    vector<int> arr3 = { 100, 112, 256, 349, 770 };
    vector<int> arr4 = { 72, 86, 113, 119, 265, 445, 892 };
    int k2 = 7;
    cout << kthElement(arr3, arr4, k2) << endl; // Output: 256

    return 0;
}
