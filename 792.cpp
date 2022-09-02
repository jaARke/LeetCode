#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        unordered_map<string, bool> m;
        for (auto& x : words) {
            if (m.find(x) != m.end()) {
                result += (m[x] ? 1 : 0);
                continue;
            }
            m[x] = false;
            int i = 0, j = 0;
            while (i < s.length() && j < x.length()) {
                if (s[i] == x[j]) {
                    j++;
                }
                i++;
            }
            if (j == x.length()) {
                result++;
                m[x] = true;
            }
        }
        return result;
    }
};