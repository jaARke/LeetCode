#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int recHelper(string& s, int idx) {
        if (idx == s.length()) {
            return 0;
        }
        if (idx > s.length() || s[idx] == '0') {
            return -1;
        }

        if (s[idx] == '1') {
            return 1 + recHelper(s, idx + 1) + recHelper(s, idx + 2);
        }
        if (s[idx] == '2' && idx < s.length() - 1 && s[idx + 1] - '0' <= 6) {
            return 1 + recHelper(s, idx + 1) + recHelper(s, idx + 2);
        }
        return recHelper(s, idx + 1);
    }
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        return 1 + recHelper(s, 0);
    }
};

int main() {
    Solution s;
    string st = "10";
    cout << s.numDecodings(st) << endl;
    return 0;
}