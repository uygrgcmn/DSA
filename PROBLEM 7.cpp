#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    // Check if any adjacent vertex has the same color
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    // Base case: All vertices are colored
    if (v == graph.size()) {
        return true;
    }

    // Try all possible colors for vertex v
    for (int c = 1; c <= m; c++) {
        // Check if color c is safe for vertex v
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            // Recur for next vertex
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }
            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> color(graph.size(), 0); // Initialize colors for all vertices to 0

    // Start coloring from vertex 0
    if (graphColoringUtil(graph, m, color, 0)) {
        return true;
    }

    return false;
}

int main() {
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = { {0, 1, 0, 1},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 0, 1, 0} };
    cout << graphColoring(graph1, M1) << endl;

    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = { {0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0} };
    cout << graphColoring(graph2, M2) << endl;

    return 0;
}
