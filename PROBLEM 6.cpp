
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& m, int i, int j, int N, string& path, vector<string>& paths) {
    // If rat reaches the destination, add the path to the result
    if (i == N - 1 && j == N - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the current cell as visited
    m[i][j] = 0;

    // Explore all four possible directions
    if (i > 0 && m[i - 1][j] == 1) { // Up
        path.push_back('U');
        backtrack(m, i - 1, j, N, path, paths);
        path.pop_back();
    }
    if (i < N - 1 && m[i + 1][j] == 1) { // Down
        path.push_back('D');
        backtrack(m, i + 1, j, N, path, paths);
        path.pop_back();
    }
    if (j > 0 && m[i][j - 1] == 1) { // Left
        path.push_back('L');
        backtrack(m, i, j - 1, N, path, paths);
        path.pop_back();
    }
    if (j < N - 1 && m[i][j + 1] == 1) { // Right
        path.push_back('R');
        backtrack(m, i, j + 1, N, path, paths);
        path.pop_back();
    }

    // Unmark the current cell to backtrack
    m[i][j] = 1;
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> paths;
    string path;

    // Check if source or destination is blocked
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0) {
        return paths;
    }

    // Call backtracking function to find all possible paths
    backtrack(m, 0, 0, N, path, paths);

    // Sort the paths lexicographically
    sort(paths.begin(), paths.end());

    return paths;
}

int main() {
    int N1 = 4;
    vector<vector<int>> matrix1 = { {1, 0, 0, 0},
                                    {1, 1, 0, 1},
                                    {1, 1, 0, 0},
                                    {0, 1, 1, 1} };
    vector<string> result1 = printPath(N1, matrix1);
    for (const auto& path : result1) {
        cout << path << " ";
    }
    cout << endl;

    int N2 = 2;
    vector<vector<int>> matrix2 = { {1, 0},
                                    {1, 0} };
    vector<string> result2 = printPath(N2, matrix2);
    if (result2.empty()) {
        cout << "-1" << endl;
    }

    return 0;
}
