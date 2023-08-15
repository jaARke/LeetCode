#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;
        int res = 0;
        for (int x : tasks) {
            freq[x]++;
        }
        for (auto iter = freq.begin(); iter != freq.end(); iter++) {
            if (iter->second < 2) {
                return -1;
            }
            res += iter->second / 3;
            res += ceil((double)(iter->second % 3) / 2.0);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    cout << s.minimumRounds(tasks) << endl;
    return 0;
}