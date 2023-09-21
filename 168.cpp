#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0) {
            char c = ('A' - 1) + (columnNumber % 26);
            if (c == '@') c = 'Z';
            res = c + res;
            columnNumber = ceil((double)columnNumber / 26) - 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    int columnNumber = 701;
    cout << s.convertToTitle(columnNumber) << endl;
    return 0;
}