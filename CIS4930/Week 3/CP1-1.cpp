#include <stack>
#include <iostream>

using namespace std;

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