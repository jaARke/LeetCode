#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 1, j = arr.size() - 2;

        while (i < j) {
            int m = (i + j) / 2;

            if (arr[m - 1] < arr[m] && arr[m + 1] < arr[m]) {
                return m;
            }
            else if (arr[m - 1] < arr[m]) {
                i = m + 1;
            }
            else {
                j = m - 1;
            }
        }
        return i;
    }
};

int main() {
    Solution s;
    vector<int> arr = {0,10,5,2};
    cout << s.peakIndexInMountainArray(arr) << endl;
    return 0;
}