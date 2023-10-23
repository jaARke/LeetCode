#include <bits/stdc++.h>

using namespace std;

int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

class Solution {
private:
    vector<string> ans;
    unordered_map<string, vector<string>> adjList;

    void recHelper(string curr) {
        while (!adjList[curr].empty()) {
            string x = adjList[curr][0];
            adjList[curr].erase(begin(adjList[curr]));

            recHelper(x);
        }
        ans.insert(begin(ans), curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& x : tickets) {
            adjList[x[0]].push_back(x[1]);
        }
        for (auto& iter : adjList) {
            sort(begin(iter.second), end(iter.second));
        }

        recHelper("JFK");
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    auto res = s.findItinerary(tickets);
    cout << "Done" << endl;
    return 0;
}