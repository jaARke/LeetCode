#include <bits/stdc++.h>

using namespace std;

/*
In the following solution, we define an array of replacements for each possible letter. On each iteration, we check if the equivalency will allow us to replace some letters with 
another that is lexicographically smaller. Since we know s1[i] and s2[i] are now equivalent, we see which replacement for s1[i] and s2[i] is larger and which is smaller. We then replace the
larger with the smaller at each point the larger occurs in the replacement array.

We keep an array to hold the lexicographically smallest valid representation for each letter. For each equivalency (s1[i] = s2[i]), we overwrite the larger representation with the smaller for 
all occurrences of the larger representation in the array.
*/

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> reps(26);
        for (int i = 0; i < 26; i++) {
            reps[i] = i + 'a';
        }
        for (int i = 0; i < s1.length(); i++) {
            char toReplace = max(reps[s1[i] - 'a'], reps[s2[i] - 'a']);
            char replacement = min(reps[s1[i] - 'a'], reps[s2[i] - 'a']);
            for (int i = 0; i < 26; i++) {
                if (reps[i] == toReplace) {
                    reps[i] = replacement;
                }
            }
        }
        string res = "";
        for (auto& c : baseStr) {
            res += reps[c - 'a'];
        }
        return res;
    }
};

/*
class Solution {
private:
    char DFS(char curr, unordered_map<char, vector<char>>& adjList, vector<bool>& seen) {
        seen[curr - 'a'] = true;
        char currMin = curr;
        for (auto& x : adjList[curr]) {
            if (!seen[x - 'a']) {
                currMin = min(currMin, DFS(x, adjList, seen));
            }
        }
        return currMin;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adjList;
        for (int i = 0; i < s1.length(); i++) {
            adjList[s1[i]].push_back(s2[i]);
            adjList[s2[i]].push_back(s1[i]);
        }
        string res = "";
        for (auto& c : baseStr) {
            vector<bool> seen(26, false);
            res += DFS(c, adjList, seen);
        }
        return res;
    }
};
*/

int main() {
    Solution s;
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    cout << s.smallestEquivalentString(s1, s2, baseStr) << endl;
    return 0;
}