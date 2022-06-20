#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * Surprisingly, the solution is found using a sliding window and keeping track of letter frequencies within the window.
 * These frequencies are compared to a master frequency table created using s1. The two frequency tables must be exactly
 * equal in order for a permutation to be found. However, order doesn't matter, so unordered maps are used.
 */

class Solution {
public:
    bool checkEqualTables(unordered_map<char, int>& t1, unordered_map<char, int>& t2) {
        auto iter = t2.begin();
        while (iter != t2.end()) {
            if (t1[iter->first] != iter->second) {
                return false;
            }
            iter++;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> master;
        unordered_map<char, int> child;
        for (auto& x : s1) {
            master[x]++;
        }
        int i = 0, j = 0;
        while (j < s2.size()) {
            if (j < s1.size() - 1) {
                child[s2[j]]++;
                j++;
                continue;
            }
            child[s2[j]]++;
            if (checkEqualTables(child, master)) {
                return true;
            }
            child[s2[i]]--;
            i++;
            j++;
        }
        return false;
    }
};

int main() {
    Solution s;
    string s1 = "ba";
    string  s2 = "eidbaooo";
    if (s.checkInclusion(s1, s2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}