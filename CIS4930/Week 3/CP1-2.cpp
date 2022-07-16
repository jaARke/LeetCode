#include <iostream>
#include <stack>

using namespace std;


int main() {
    stack<int> s;
    string in;
    cin >> in;

    s.push(1);
    for (int i = 2; i <= in.length(); i++) {
        if (in[i - 2] == 'l') {
            s.push(i);
        }
        if (in[i - 2] == 'r') {
            cout << s.top() << "\n";
            s.pop();
            s.push(i);
        }
    }
    while (!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }
    return 0;
}