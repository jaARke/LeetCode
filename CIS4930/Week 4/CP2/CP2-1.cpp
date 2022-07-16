#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long k;
        cin >> n;
        cin >> k;
        
        map<int, priority_queue<int>> rams;
        vector<int> costs;
        for (int j = 0; j < n; j++) {
            int ai;
            cin >> ai;
            costs.push_back(ai);
        }
        for (int j = 0; j < n; j++) {
            int bi;
            cin >> bi;
            rams[costs[j]].push(bi);
        }

        while(!rams.empty()) {
            auto iter = rams.lower_bound(k);
            while (iter == rams.end() || (iter != rams.begin() && iter->first > k)) {
                iter--;
            }
            if (!(iter->first > k)) {
                k += iter->second.top();
                iter->second.pop();
                if (iter->second.empty()) {
                    rams.erase(iter);
                }
            }
            else {
                break;
            }
        }
        cout << k << "\n";
    }
    return 0;
}