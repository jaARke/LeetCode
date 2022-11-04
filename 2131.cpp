#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int res = 0;
        bool flag = false;
        for (auto& str : words) {
            string rev = {str[1], str[0]};
            if (m[rev]) {
                res += 4;
                m[rev]--;
            }
            else {
                m[str]++;
            }
        }
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if(iter->first[0] == iter->first[1] && iter->second) {
                res += 2;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"qo","fo","fq","qf","fo","ff","qq","qf","of","of","oo","of","of","qf","qf","of"};
    cout << s.longestPalindrome(words) << endl;
    return 0;
}