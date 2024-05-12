#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a meeting
struct Meeting {
    int start, end, index;
};

// Comparator function to sort meetings by their end times
bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);

    // Store meetings in a vector of structs
    for (int i = 0; i < n; i++) {
        meetings[i] = { start[i], end[i], i };
    }

    // Sort meetings by end times
    sort(meetings.begin(), meetings.end(), compare);

    int count = 1; // At least one meeting can be held
    int endTime = meetings[0].end;

    // Iterate through sorted meetings, select non-overlapping ones
    for (int i = 1; i < n; i++) {
        if (meetings[i].start > endTime) {
            count++;
            endTime = meetings[i].end;
        }
    }

    return count;
}

int main() {
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(start) / sizeof(start[0]);

    cout << "Maximum number of meetings: " << maxMeetings(start, end, n) << endl;

    return 0;
}
