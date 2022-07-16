#include <vector>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        stack<int> s;
        while (i < pushed.size() || j < popped.size()) {
            if (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
            else {
                if (i >= popped.size()) {
                    return false;
                }
                s.push(pushed[i]);
                i++;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,3,5,1,2};
    if (s.validateStackSequences(pushed, popped)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}