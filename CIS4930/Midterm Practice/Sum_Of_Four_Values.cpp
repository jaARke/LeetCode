#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    /*
    Reduce the problem to two-sum by storing the sums of all pairs of values and then finding two pair sums that equal target.
    You must check whether or not the pairs share any indices.
    */
    unordered_multimap<int, pair<int, int>> pairs;
    vector<int> prev;
    for (int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        for (int j = 0; j < prev.size(); j++) {
            pairs.emplace(prev[j] + ni, make_pair(i + 1, j + 1));
        }
        prev.push_back(ni);
    }
    bool flag = true;
    auto iter = pairs.begin();
    while (iter != pairs.end()) {
        auto iter2 = pairs.find(x - iter->first);
        if (iter2 != pairs.end()) {
            if (iter2->second.first != iter->second.first && iter2->second.second != iter->second.second && iter->second.second != iter2->second.first && iter->second.first != iter2->second.second) {
                cout << iter->second.first << " " << iter->second.second << " " << iter2->second.first << " " << iter2->second.second;
                flag = false;
                break;
            }
        }
        iter++;
    }
    if (flag) {
        cout << "IMPOSSIBLE";
    }
    return 0;
}