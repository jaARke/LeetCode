#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

bool runBFS(pair<int, int>& queen, pair<int, int>& targ, int n, long long source) {
    unordered_set<long long> visited;
    queue<long long> q;
    q.push(source);

    while (!q.empty()) {
        long long x = q.front() / 1e6;
        long long y = q.front() % (long long)1e6;
        if (visited.find(q.front()) != visited.end() || x - queen.first == y - queen.second || x == queen.first || y == queen.second) {
            q.pop();
            continue;
        }
        if (x == targ.first && y == targ.second) {
            return true;
        }
        bool flag1 = false;
        bool flag2 = false;
        if (y + 1 <= n) {  
            q.push((x * 1e6) + (y + 1));
            flag1 = true;
        }
        if (y - 1 > 0) {   
            q.push((x * 1e6) + (y - 1));
            flag2 = true;
        }
        if (x + 1 <= n) { 
            q.push(((x + 1) * 1e6) + y);
            if (flag1) {
                q.push(((x + 1) * 1e6) + (y + 1));
            }
            if (flag2) {
                q.push(((x + 1) * 1e6) + (y - 1));
            }
        }
        if (x - 1 > 0) {   
            q.push(((x - 1) * 1e6) + y);
            if (flag1) {
                q.push(((x - 1) * 1e6) + (y + 1));
            }
            if (flag2) {
                q.push(((x - 1) * 1e6) + (y - 1));
            }
        }
        visited.insert(q.front());
        q.pop();
    }
    return false;
}


int main() {
    int n;
    cin >> n;

    pair<int, int> queen;
    cin >> queen.first >> queen.second;
    pair<int, int> start;
    cin >> start.first >> start.second;
    pair<int, int> targ;
    cin >> targ.first >> targ.second;

    long long source = (((long long)(start.first) * 1e6) + start.second);
    if (runBFS(queen, targ, n, source)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}