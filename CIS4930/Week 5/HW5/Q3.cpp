#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compDolls(const pair<int, int> lhs, const pair<int, int> rhs) {    // Sort by ascending width. Or, in case of tie, descending height
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    return lhs.first > rhs.first;
}

int LIS(vector<pair<int, int>>& dolls) {  // Compute LIS on sorted heights - bottom-up got TLE. This way uses binary search and is a little faster
    if (dolls.empty()) {
        return 0;
    }
    int result = 0;
    vector<int> lis(dolls.size(), INT32_MAX);

    int maxIndex = -1;
    for (int j = 0; j < lis.size(); j++) {
        auto iter = upper_bound(lis.begin(), lis.end(), dolls[j].second);
        if (iter - lis.begin() > maxIndex) {
            result++;
            maxIndex = iter - lis.begin();
        }
        *iter = dolls[j].second;
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