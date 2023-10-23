#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n + 1, 0);
        vector<vector<int>> preReqs(n + 1); // preReqs[i] = [courses for which course i is a pre req]

        for (auto& x : relations) {
            preReqs[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 1; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) pq.push({time[i - 1], i});
        }

        int currTime = 0;
        while (!pq.empty()) {
            currTime += max(pq.top().first - currTime, 0);
            for (int x : preReqs[pq.top().second]) {
                if (--inDegree[x] == 0) pq.push({time[x - 1] + currTime, x});
            }
            pq.pop();
        }
        return currTime;
    }
};

int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> relations = {{1,3}, {2,3}};
    vector<int> time = {3,2,5};

    cout << s.minimumTime(n, relations, time) << endl;
    return 0;
}