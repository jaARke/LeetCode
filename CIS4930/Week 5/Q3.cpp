#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compDolls(const pair<int, int>& lhs, const pair<int, int>& rhs) {    // Sort by descending width. Or, in case of tie, ascending height
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    return lhs.first > rhs.first;
}

int LIS(vector<pair<int, int>>& dolls) {  // Compute LIS on sorted heights - bottom-up got TLE. This way uses binary search and is a little faster
    vector<int> LIS;
    int result = 0;
    for (int j = 0; j < dolls.size(); j++) {
        auto iter = upper_bound(LIS.begin(), LIS.end(), dolls[j].second);
        if (iter == LIS.end()) {
            result++;
            LIS.push_back(dolls[j].second);
        }
        else {
            *iter = dolls[j].second;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<pair<int, int>> dolls;
        for (int j = 0; j < m; j++) {
            int w;
            int h;
            cin >> w >> h;
            dolls.push_back(make_pair(w, h));
        }
        sort(dolls.begin(), dolls.end(), compDolls);
        cout << LIS(dolls) << "\n";
    }
    return 0;
}