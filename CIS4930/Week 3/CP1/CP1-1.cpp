#include <stack>
#include <iostream>

using namespace std;

/*
Push opening characters onto the stack. Upon encountering a closing character, check if it matches the opening character currently on top of the stack. Return false if it doesn't match,
or if the stack is empty. Return true if the stack is empty at the end, false otherwise.
*/

bool checkString(string in) {
    stack<char> s;

    for (int j = 0; j < in.length(); j++) {
        if (in[j] == '(' || in[j] == '[') {
            s.push(in[j]);
        }
        else {
            if (s.empty()) {
                return false;
            }
            if (in[j] == ')' && s.top() != '(') {
                return false;
            }
            if (in[j] == ']' && s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }
    return (s.empty());
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string in;
        getline(cin, in);
        if (in.empty() || checkString(in)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}