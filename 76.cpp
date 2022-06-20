#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
private:
    bool check(unordered_map<char, int>& master, unordered_map<char, int>& child) {
        auto iter = master.begin();
        while (iter != master.end()) {
            if (child[iter->first] < iter->second) {
                return false;
            }
            iter++;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }
        int resLen = INT32_MAX;
        string res;
        unordered_map<char, int> master;
        unordered_map<char, int> child;
        for (auto &x: t) {
            master[x]++;
        }
        int i = 0, j = 0;
        while (j < s.length()) {
            child[s[j]]++;
            if (check(master, child)) {
                while (child[s[i]] > master[s[i]]) {
                    child[s[i]]--;
                    i++;
                }
                if (j - i + 1 < resLen) {
                    resLen = j - i + 1;
                    res = s.substr(i, j - i + 1);
                }
            }
            j++;
        }
        return res;
    }
};

int main() {
    Solution s;
    string st = "ADOBECODEBANC";
    string t = "ABC";
    cout << s.minWindow(st, t) << endl;
    return 0;
}