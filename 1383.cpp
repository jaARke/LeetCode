#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < speed.size(); i++) {
            v.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(v.begin(), v.end());
        long long sum = 0;
        long long res = INT32_MIN;
        while (!v.empty()) {
            if (pq.size() == k) {
                sum -= pq.top().first;
                pq.pop();
            }
            pq.push(make_pair(v.back().second, v.back().first));
            sum += v.back().second;
            res = max(res, sum * v.back().first);
            v.pop_back();
        }
        return res % (long long)(1e9 + 7);
    }
};