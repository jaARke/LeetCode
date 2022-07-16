#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {    // Sort the dolls in descending order of width. If tie, then ascending order of height
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    return lhs.first > rhs.first;
}

int LIS(vector<pair<int, int>>& v) {    // Once the dolls are sorted according to the above, the answer is the longest increasing subsequence of heights
    vector<int> LIS;
    int result = 0;
    for (int j = 0; j < v.size(); j++) {
        auto iter = upper_bound(LIS.begin(), LIS.end(), v[j].second);
        if (iter == LIS.end()) {
            result++;
            LIS.push_back(v[j].second);
        }
        else {
            *iter = v[j].second;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<pair<int, int>> v;
        for (int j = 0; j < n; j++) {
            int w, h;
            cin >> w >> h;
            v.push_back(make_pair(w, h));
        }
        sort(v.begin(), v.end(), cmp);
        cout << LIS(v) << endl;
    }
    return 0;
}