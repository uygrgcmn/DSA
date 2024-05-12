#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& s, int start, int end) {
    // Check if the part is within the range [0, 255] and does not have leading zeros if its length is greater than 1
    if (end - start + 1 > 1 && s[start] == '0') {
        return false;
    }
    int num = stoi(s.substr(start, end - start + 1));
    return num >= 0 && num <= 255;
}

void generateIP(string s, vector<string>& result, int pos, int parts, string current) {
    // Base case: If all four parts are formed
    if (parts == 4) {
        // Check if all characters are used and add to the result
        if (pos == s.length()) {
            result.push_back(current);
        }
        return;
    }

    // Iterate through all possible segments for the current part
    for (int i = 1; i <= 3 && pos + i <= s.length(); i++) {
        string part = s.substr(pos, i);
        // Check if the current segment forms a valid part of an IP address
        if (isValidPart(s, pos, pos + i - 1)) {
            // If not the first part, add a '.' before adding the segment
            string separator = (parts == 0) ? "" : ".";
            generateIP(s, result, pos + i, parts + 1, current + separator + part);
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    generateIP(S, result, 0, 0, "");
    return result.empty() ? vector<string>{"-1"} : result;
}

int main() {
    string S1 = "1111";
    vector<string> result1 = genIp(S1);
    for (const auto& ip : result1) {
        cout << ip << endl;
    }

    string S2 = "55";
    vector<string> result2 = genIp(S2);
    for (const auto& ip : result2) {
        cout << ip << endl;
    }

    return 0;
}
