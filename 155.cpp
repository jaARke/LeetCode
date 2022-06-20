#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> s;    // First entry holds the actual value, second holds the minimum of values beneath (and including) that
                                // value
public:
    MinStack() = default;

    void push(int val) {
        if (!s.empty()) {
            s.push(make_pair(val, min(s.top().second, val)));   // Push {val, min based on min of top element and val}
        }
        else {
            s.push(make_pair(val, val));    // Val must be the minimum so push {val, val}
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;  // Minimum is always the top element's minimum entry
    }
};

/*
The following solution requires a lot of space but runs at the same speed as the one above
class MinStack {
private:
    map<int, int> counts;
    stack<int> s;
public:
    MinStack() = default;

    void push(int val) {
        s.push(val);
        counts[val]++;
    }

    void pop() {
        if (--counts[s.top()] == 0) {
            counts.erase(s.top());
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return counts.begin()->first;
    }
};
 */
