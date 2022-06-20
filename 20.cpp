#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string& s) {
        stack<char> sta;
        for (char& i : s) {
            if (i == '[' || i == '(' || i == '{') {
                sta.push(i);
            }
            else {
                if (sta.empty()) {
                    return false;
                }
                if (i == ']' && sta.top() != '[') {
                    return false;
                }
                if (i == ')' && sta.top() != '(') {
                    return false;
                }
                if (i == '}' && sta.top() != '{') {
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};

int main() {
    Solution s;
    string st = "()";
    if (s.isValid(st)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}

