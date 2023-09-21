#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freqs(26, 0);
        stack<int> st;
        for (char& c : s) {
            freqs[c - 'a']++;
        }
        sort(begin(freqs), end(freqs));

        int i = 0;
        for (; freqs[i] == 0; i++);
        
        for (int j = 1; j < freqs[i]; j++) {
            st.push(j);
        }

        int res = 0;
        for (i = i + 1; i < freqs.size(); i++) {
            if (freqs[i] == freqs[i - 1]) {
                if (st.empty()) res += freqs[i];
                else {
                    res += (freqs[i] - st.top());
                    st.pop();
                }
            }
            else {
                for (int j = freqs[i - 1] + 1; j < freqs[i]; j++) {
                    st.push(j);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "aaabbbcc";
    cout << s.minDeletions(str) << endl;
    return 0;
}