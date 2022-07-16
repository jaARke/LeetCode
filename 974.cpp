#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mods(k, 0);
        int sum = 0;
        int result = 0;
        mods.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mods[((sum % k) + k) % k]++;    // Makes it possible to deal with negative elements
        }
        for (int i = 0; i < mods.size(); i++) {
            if (mods[i] > 1) {
                result += (mods[i] * (mods[i] - 1)) / 2;
            }
        }
        result += mods[0];  // Lone divisible elements
        return result;
    }
};

int main() {
    int n = -4;
    cout << n % 4 << endl;
    return 0;
}