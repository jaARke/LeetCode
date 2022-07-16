#include <string>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                if (st.empty()) {
                    s.erase(s.begin() + i);
                    i--;
                }
                else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            auto sti = st.top();
            st.pop();
            s.erase(s.begin() + sti);
        }
        return s;
    }
};

int main() {
    Solution s;
    string st = "lee(t(c)o)de)";
    cout << s.minRemoveToMakeValid(st) << endl;
    return 0;
}