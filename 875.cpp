#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

/*
 * Amazingly, the way to solve this question is to binarily search for the solution. We know the initial bounds of this
 * search are 1 and the maximum element in the piles vector. Using these bounds, we use binary search to try possible
 * answer values within these bounds. If all the piles cannot be eaten with a given value of "mid", we know the answer
 * must be higher than what we are currently considering. If the piles can be eaten, we make the window smaller anyhow,
 * in order to find the minimum eating speed with which all the piles can be finished.
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int i = 1, j = piles[piles.size() - 1];
        while (i < j) {
            int mid = (i + j) / 2;
            int tempH = h;
            bool flag = false;
            for (int pile : piles) {
                tempH -= ceil((double)pile / (double)mid);
                if (tempH < 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                i = mid + 1;
            }
            else {
                j = mid;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> piles = {30,11,23,4,20};
    int h = 5;
    cout << s.minEatingSpeed(piles, h) << endl;
    return 0;
}