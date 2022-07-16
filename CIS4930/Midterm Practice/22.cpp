#include <iostream>
#include <stack>

using namespace std;

int main() {
    string in;
    cin >> in;

    stack<int> s;
    bool result = false;
    for (int i = 0; i < in.length(); i++) {
        if (!s.empty() && s.top() == in[i]) {
            s.pop();
            result = !result;
        }
        else {
            s.push(in[i]);
        }
    }
    if (result) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}