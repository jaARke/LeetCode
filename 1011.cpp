#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Compute the bounds of the binSearch
        int left = INT32_MIN, right = 0;
        for (auto& x : weights) {
            right += x;
            left = max(left, x);
        }
        // Check if all packages need to be carried in one day -> ans is the sum of all package weights
        if (days == 1) {
            return right;
        }
        // Start binSearch
        while (left < right) {
            int mid = (left + right) / 2;
            // Check if the computed capacity can carry all packages in given number of days
            int numDays = 1;
            int tempMid = mid;
            for (auto& x : weights) {
                if (tempMid - x < 0) {
                    tempMid = mid - x;
                    if (++numDays > days) {
                        break;
                    }
                }
                else {
                    tempMid -= x;
                }
            }
            // Move left and right depending on if the capacity works
            if (numDays > days) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    cout << s.shipWithinDays(weights, days) << endl;
    return 0;
}