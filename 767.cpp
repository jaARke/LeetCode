#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freqs(26);
        priority_queue<pair<int, int>> pq;
        for (char& c : s) {
            freqs[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freqs[i] == 0) continue;
            pq.push(make_pair(freqs[i], i));
        }

        string res = "";
        while (pq.size() > 1) {
            auto x = pq.top();
            pq.pop();
            auto y = pq.top();
            pq.pop();

            res.push_back(x.second + 'a');
            res.push_back(y.second + 'a');
            if (--x.first > 0) pq.push(x);
            if (--y.first > 0) pq.push(y);
        }
        
        if (!pq.empty()) {
            if (pq.top().first != 1) {
                return "";
            }
            res.push_back(pq.top().second + 'a');
        }
        return res;
    }
};

int main() {
    Solution s;
    string str1 = "aab";
    string str2 = "ogccckcwmbmxtsbmozli";
    cout << s.reorganizeString(str1) << endl;
    return 0;
}