#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(make_pair(temperatures[i], i));
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> res(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!pq.empty() && pq.top().first < temperatures[i]) {
                res[pq.top().second] = i - pq.top().second;
                pq.pop();
            }
            pq.push(make_pair(temperatures[i], i));
        }
        return res;
    }
};
 */

int main() {
    Solution s;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto res = s.dailyTemperatures(temperatures);
    cout << "Done!" << endl;
    return 0;
}