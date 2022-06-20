#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& x : tokens) {
            if (x == "+") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2 + op1);
            }
            else if (x == "-") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2 - op1);
            }
            else if (x == "*") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2 * op1);
            }
            else if (x == "/") {
                int op1 = s.top();
                s.pop();
                int op2 = s.top();
                s.pop();
                s.push(op2 / op1);
            }
            else {
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};