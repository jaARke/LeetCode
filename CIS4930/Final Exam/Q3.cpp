#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool custComp(pair<int, int>& lhs, pair<int, int>& rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    else {
        return lhs.first < rhs.first;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> heights;
        for (int j = 0; j < n; j++) {
            int hi;
            cin >> hi;
            heights.push_back(hi);
        }
        vector<pair<int, int>> list;
        for (int j = 0; j < n; j++) {
            int si;
            cin >> si;
            list.push_back(make_pair(heights[j], si));
        }
        sort(list.begin(), list.end(), custComp);
        vector<int> res(n);
        int count = 0;
        int offset = 0;
        int prev = INT32_MIN;
        int j = 0;
        while (j < list.size()) {
            if (prev < list[j].second) {
                offset += count;
                count = 0;
            }
            res[list[j].second + offset] = list[j].first;
            count++;
            prev = list[j].second;
            j++;
        }
        for (int k = 0; k < res.size(); k++) {
            cout << res[k] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
