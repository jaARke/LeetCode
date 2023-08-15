#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) {
            return -1;
        }

        int i = 1, j = *max_element(begin(dist), end(dist)) * 100;

        while (i < j) {
            int m = (i + j) / 2;
            double currAns = 0;

            for (int k = 0; k < dist.size() && currAns <= hour; k++) {
                if (k < dist.size() - 1) {
                    currAns += ceil((double)dist[k] / (double)m);
                }
                else {
                    currAns += ((double)dist[k] / (double)m);
                }
            }

            if (currAns <= hour) {
                j = m;
            }
            else {
                i = m + 1;
            }
        }
        return j;
    }
};

int main() {
    Solution s;
    vector<int> dist = {1,1,100000};
    double hour = 2.01;
    cout << s.minSpeedOnTime(dist, hour) << endl;
    return 0;
}