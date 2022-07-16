#include <stack>
#include <queue>
#include <unordered_set>
#include <set>
#include <iostream>

using namespace std;

/*
The better way of solving this problem is to use GCD, but this is the way we learned in class. Got TLE using DFS so switched to BFS. May be able to increase performance if visit checking occurs
before pushing to queue.
*/


class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        queue<long long> todo;
        unordered_set<long long> seen;
        todo.push((0 * 1e6) + 0);   // Translation equation

        while (!todo.empty()) {
            long long ti = todo.front();
            todo.pop();
            if (seen.find(ti) != seen.end()) {
                continue;
            }
            int j1 = ti / 1e6;
            int j2 = ti % (long long)1e6;
            if (j1 == targetCapacity || j2 == targetCapacity || j1 + j2 == targetCapacity) {
                return true;
            }
            // Fill jug 1 with water
            long long p1 = (jug1Capacity * 1e6) + j2;
            todo.push(p1);
            // Fill jug 2 with water
            long long p2 = (j1 * 1e6) + jug2Capacity;
            todo.push(p2);
            // Empty jug 1
            long long p3 = (0 * 1e6) + j2;
            todo.push(p3);
            // Empty jug 2
            long long p4 = (1e6 * j1) + 0;
            todo.push(p4);
            // Pour from jug 1 into jug 2 and vice versa
            long long p5;
            long long p6;
            if (j1 + j2 > jug2Capacity) {  // Pour until jug 2 is full
                p5 = ((j1 - (jug2Capacity - j2)) * 1e6) + jug2Capacity;
                p6 = (jug1Capacity * 1e6) + (j2 - (jug1Capacity - j1));
            }
            else {  // Pour until jug 1 is empty
                p5 = (0 * 1e6) + (j1 + j2);
                p6 = ((j1 + j2) * 1e6) + 0;
            }
            todo.push(p5);
            todo.push(p6);

            seen.insert(ti);
        }
        return false;
    }
};

int main() {
    Solution s;
    int jug1Capacity = 34;
    int jug2Capacity = 5;
    int targetCapacity = 6;
    if (s.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}