#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A'; // Assuming uppercase letters
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    // Check if a word exists in the trie
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'A'; // Assuming uppercase letters
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEndOfWord;
    }

    // Check if a prefix exists in the trie
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'A'; // Assuming uppercase letters
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr;
    }
};

void findWords(vector<vector<char>>& board, int i, int j, TrieNode* node, string word, unordered_set<string>& result, vector<vector<bool>>& visited) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || !node->children[board[i][j] - 'A']) {
        return;
    }

    node = node->children[board[i][j] - 'A'];
    word += board[i][j];

    if (node->isEndOfWord) {
        result.insert(word);
    }

    visited[i][j] = true;

    // Explore all 8 adjacent cells
    findWords(board, i + 1, j, node, word, result, visited);
    findWords(board, i - 1, j, node, word, result, visited);
    findWords(board, i, j + 1, node, word, result, visited);
    findWords(board, i, j - 1, node, word, result, visited);
    findWords(board, i + 1, j + 1, node, word, result, visited);
    findWords(board, i + 1, j - 1, node, word, result, visited);
    findWords(board, i - 1, j + 1, node, word, result, visited);
    findWords(board, i - 1, j - 1, node, word, result, visited);

    visited[i][j] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    Trie trie;
    for (string word : dictionary) {
        trie.insert(word);
    }

    int rows = board.size();
    int cols = board[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    unordered_set<string> result;

    // Explore all possible starting cells on the board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            string word = "";
            findWords(board, i, j, trie.root, word, result, visited);
        }
    }

    // Convert set to vector and return
    vector<string> res(result.begin(), result.end());
    return res;
}

int main() {
    int N1 = 1, R1 = 3, C1 = 3;
    vector<string> dictionary1 = { "CAT" };
    vector<vector<char>> board1 = { {'C', 'A', 'P'}, {'A', 'N', 'D'}, {'T', 'I', 'E'} };
    vector<string> result1 = wordBoggle(board1, dictionary1);
    for (const string& word : result1) {
        cout << word << " ";
    }
    cout << endl;

    int N2 = 4, R2 = 3, C2 = 3;
    vector<string> dictionary2 = { "GEEKS", "FOR", "QUIZ", "GO" };
    vector<vector<char>> board2 = { {'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'} };
    vector<string> result2 = wordBoggle(board2, dictionary2);
    for (const string& word : result2) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
