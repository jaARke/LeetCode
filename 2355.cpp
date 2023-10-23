#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        deque<int> q;
        long long ans = 0, currSum = 0;

        for (int i : books) {
            if (!q.empty() && i <= q.back()) {
                int k = i - 1;
                int j = q.size() - 1;
                for (; j >= 0 && k > 0; j--) {
                    k = min(k, q[j]);
                    currSum -= q[j] - k;
                    q[j] = k--;
                }
                for (int l = 0; l <= j; l++) {
                    currSum -= q.front();
                    q.pop_front();
                }
            }
            q.push_back(i);
            currSum += i;
            ans = max(ans, currSum);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> books = {0,3,1,5,4};
    cout << s.maximumBooks(books) << endl;
    return 0;
}