#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<char> v(strs[0].length(), 'a');
        int res = 0;
        for (string& x : strs) {
            for (int i = 0; i < x.length(); i++) {
                if (v[i] == '~') {
                    continue;
                }
                if (v[i] > x[i]) {
                    res++;
                    v[i] = '~';
                }
                else {
                    v[i] = x[i];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"xflbebb","fzqetdc","xktuxef","gfvxchu","goyyhiv"};
    cout << s.minDeletionSize(strs) << endl;
    return 0;
}