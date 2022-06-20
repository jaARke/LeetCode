#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& x : nums) {
            m[x]++;
        }
        auto iter = m.begin();
        while (iter != m.end()) {
            if (pq.size() < k) {
                pq.push(make_pair(iter->second, iter->first));
            }
            else if (pq.top().first < iter->second) {
                pq.pop();
                pq.push(make_pair(iter->second, iter->first));
            }
            iter++;
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto ans = s.topKFrequent(nums, k);
    cout << "test";
    return 0;
}