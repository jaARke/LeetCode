#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev = 0;
        for (auto& x : arr) {
            if (k - ((x - prev) - 1) <= 0) {
                return prev + k;
            }
            k -= (x - prev) - 1;
            prev = x;
        }
        return prev + k;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    cout << s.findKthPositive(arr, k) << endl;
    return 0;
}