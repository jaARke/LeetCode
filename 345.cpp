#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = s.length() - 1;
        while (i < j) {
            bool ib = vowels.find(tolower(s[i])) != vowels.end();
            bool jb = vowels.find(tolower(s[j])) != vowels.end();
            if (ib && jb) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if (ib) {
                j--;
            }
            else if (jb) {
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        return s;
    }
    /*
    string reverseVowels(string s) {
        stack<int> idxs;
        vector<char> vowels;
        for (int i = 0; i < s.length(); i++) {
            char ch = tolower(s[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                idxs.push(i);
                vowels.push_back(s[i]);
            }
        }
        for (auto& c : vowels) {
            s[idxs.top()] = c;
            idxs.pop();
        }
        return s;
    }
    */
};