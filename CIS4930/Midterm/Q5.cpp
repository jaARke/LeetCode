#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int si, di;
        cin >> si >> di;
        times.emplace_back(si, si + di);
    }
    // Sort all the battles in order of increasing start time
    sort(times.begin(), times.end());

    priority_queue<int, vector<int>, greater<>> prioQ;   // Holds battle end times
    prioQ.push(times[0].second);
    int currMax = 0;
    for (int i = 1; i < n; i++) {
        while (!prioQ.empty() && prioQ.top() <= times[i].first) {   // The earliest end time is before the current battle's start time -> no conflict
            prioQ.pop();
        }
        /*
         * We know that all the rest of the battles in the queue conflict with the current battle.
         * This was the benefit of sorting the battle start times to begin with. We know that each battle in the
         * priority queue start before the battle currently being considered. Thus, if the end times in the priority queue
         * are after the start time being considered, the two battles certainly conflict.
         */

        prioQ.push(times[i].second);
        currMax = max(currMax, (int)prioQ.size());
    }
    cout << currMax;
    return 0;
}