#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> log;
        log[0] = 1;
        int sum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (log.find(sum - k) != log.end()) {
                result += log[sum - k];
            }
            log[sum] += 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> in = {1, 1, 1};
    int k = 2;
    cout << s.subarraySum(in, k) << endl;

    return 0;
}