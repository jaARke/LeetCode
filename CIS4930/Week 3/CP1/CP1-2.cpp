#include <iostream>
#include <stack>

using namespace std;


int main() {
    stack<int> s;
    string in;
    cin >> in;
    /*
    In either case of dodge direction, push the current index value onto the top of the stack. If the squirrel goes right, you must first pop and print the value at the top of the stack,
    as the squirrel will go no further left than that value. When the squirrel is done dodging, pop and print each value from the stack until it is empty.
    */
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