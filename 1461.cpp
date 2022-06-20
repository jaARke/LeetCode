#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k >= s.length()) {
            return false;
        }
        int i = 0;
        unordered_set<string> seen;
        while (i + k - 1 < s.length()) {
            seen.insert(s.substr(i, k));
            if (seen.size() == 1 << k) {
                return true;
            }
            i++;
        }
        return false;
    }
};

int main() {
    Solution s;
    string st = "00110110";
    int k = 2;
    if (s.hasAllCodes(st, k)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}