#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> seen;
        vector<char> chars = {'A', 'C', 'T', 'G'};
        queue<pair<string, int>> q;
        q.push(make_pair(startGene, 0));
        int res = INT32_MAX;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (curr.first == endGene) {
                res = min(res, curr.second);
                continue;
            }
            for (int i = 0; i < 8; i++) {
                char temp = curr.first[i];
                for (auto& c : chars) {
                    curr.first[i] = c;
                    if (seen.find(curr.first) == seen.end() && bankSet.find(curr.first) != bankSet.end()) {
                        q.push(make_pair(curr.first, curr.second + 1));
                        seen.insert(curr.first);
                    }
                }
                curr.first[i] = temp;
            }
        }
        return (res == INT32_MAX ? -1 : res);
    }
};

int main() {
    Solution s;
    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank = {"AACCGATT","AACCGATA","AAACGATA","AAACGGTA"};
    cout << s.minMutation(startGene, endGene, bank) << endl;
    return 0;
}