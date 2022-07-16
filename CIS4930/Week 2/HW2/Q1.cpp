#include <stack>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

string runCase(int n) {
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool stack = true;
    bool queue = true;
    bool prioQueue = true;

    for (int i = 0; i < n; i++) {
        int op;
        int num;
        cin >> op;
        cin >> num;

        if (op == 1) {
            s.push(num);
            q.push(num);
            pq.push(num);
        }
        else {
            if (s.empty()) {    // If one's empty, they're all empty
                stack = false;
                queue = false;
                prioQueue = false;
            }
            else {
                if (stack && s.top() != num) {
                    stack = false;
                }
                if (queue && q.front() != num) {
                    queue = false;
                }
                if (prioQueue && pq.top() != num) {
                    prioQueue = false;
                }
                s.pop();
                q.pop();
                pq.pop();
            }
        }
    }
    if (stack) {
        if (queue || prioQueue) {
            return "not sure";
        }
        else {
            return "stack";
        }
    }
    else if (queue) {
        if (prioQueue) {
            return "not sure";
        }
        else {
            return "queue";
        }
    }
    else if (prioQueue) {
        return "priority queue";
    }
    else {
        return "impossible";
    }
}

int main() {
    string n;
    while (getline(cin, n)) {
        try {
            cout << runCase(stoi(n)) << endl;
        }
        catch (exception) {
            break;
        }
        cin.ignore();
    }
    return 0;
}