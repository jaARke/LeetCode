#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * Solution is simple: go through every word and take out each letter one-by-one. Check if the resulting string is
 * one of the other words. If so, set m[current word] = max(m[current word], m[other word] + 1). At the end of each
 * iteration check if you can update result.
 */

class Solution {
private:
    static bool cmp(string& lhs, string& rhs) {
        return lhs.length() < rhs.length();
    }
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        int result = 1;
        sort(words.begin(), words.end(), cmp);
        for (auto& x : words) {
            for (int i = 0; i < x.length(); i++) {
                string del = x.substr(0, i) + x.substr(i + 1);
                m[x] = max(m[x], m[del] + 1);
            }
            result = max(result, m[x]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> words = {"wnyxmflkf","xefx","usqhb","ttmdvv","hagmmn","tmvv","pttmdvv","nmzlhlpr","ymfk","uhpaglmmnn","zckgh","hgmmn","isqxrk","isqrk","nmzlhpr","uysyqhxb","haglmmn","xfx","mm","wymfkf","tmdvv","uhaglmmn","mf","uhaglmmnn","mfk","wnymfkf","powttkmdvv","kwnyxmflkf","xx","rnqbhxsj","uysqhb","pttkmdvv","hmmn","iq","m","ymfkf","zckgdh","zckh","hmm","xuefx","mv","iqrk","tmv","iqk","wnyxmfkf","uysyqhb","v","m","pwttkmdvv","rnqbhsj"};
    cout << s.longestStrChain(words) << endl;
    return 0;
}
