#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (m[key].empty()) {
            return "";
        }
        /*
         * Cheater method using STL binary search
        string useless = "";
        auto iter = lower_bound(m[key].begin(), m[key].end(), make_pair(timestamp, useless));
        if (iter == m[key].begin() && iter->first > timestamp) {
            return "";
        }
        if (iter == m[key].end() || iter->first > timestamp) {
            iter--;
        }
        return iter->second;
         */
        int i = 0, j = m[key].size() - 1;
        while (i < j - 1) {
            int mid = (i + j) / 2;
            if (m[key][mid].first < timestamp) {
                i = mid;
            }
            else if (m[key][mid].first > timestamp) {
                j = mid - 1;
            }
            else {
                return m[key][mid].second;
            }
        }
        if (m[key][i].first > timestamp) {
            return "";
        }
        if (m[key][j].first <= timestamp) {
            return m[key][j].second;
        }
        return m[key][i].second;
    }
};