#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> alpha(26);
        for (int i = 0; i < order.length(); i++) {
            alpha[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            while (j < words[i].length() && j < words[i - 1].length() && words[i][j] == words[i - 1][j]) { // Traverse to a choking point
                j++;
                continue;
            }
            if (j == words[i - 1].length()) {
                continue;
            }
            if (j == words[i].length()) {
                return false;
            }
            if (alpha[words[i][j] - 'a'] < alpha[words[i - 1][j] - 'a']) {
                return false;
            }
        } 
        return true;
    }
};

int main() {
    Solution s;
    vector<string> words = {"word", "world", "row"};
    string order = "worldabcefghijkmnpqstuvxyz";
    cout << (s.isAlienSorted(words, order) ? "True" : "False") << endl;
    return 0;
}

