#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    struct SegTree {
        SegTree* leftNode;
        SegTree* rightNode;
        int count;
        long minEl, maxEl;

        SegTree(vector<long>& sums, int left, int right) {  // Build the tree
            if (left > right) {
                return;
            }
            leftNode = nullptr;
            rightNode = nullptr;
            maxEl = sums[right];
            minEl = sums[left];
            count = 0;
            if (left == right) {
                return;
            }
            int mid = (left + right) / 2;
            if (right >= mid + 1) {
                rightNode = new SegTree(sums, mid + 1, right);
            }
            if (left <= mid) {
                leftNode = new SegTree(sums, left, mid);
            }
        }
        void update(long val) {
            if (val < minEl || val > maxEl) {   // Doesn't fit within this range
                return;
            }
            count++;
            if (rightNode != nullptr && val >= rightNode->minEl) {
                rightNode->update(val);
            }
            if (leftNode != nullptr && val <= leftNode->maxEl) {
                leftNode->update(val);
            }
        }
        int countRange(long lower, long upper) {
            if (minEl > upper || maxEl < lower) {
                return 0;
            }
            if (minEl >= lower && maxEl <= upper) {
                return count;
            }
            int leftRes = 0;
            int rightRes = 0;
            if (leftNode != nullptr) {
                leftRes = leftNode->countRange(lower, upper);
            }
            if (rightNode != nullptr) {
                rightRes = rightNode->countRange(lower, upper);
            }
            return leftRes + rightRes;
        }
    };

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long currSum = 0;
        int n = nums.size();
        unordered_set<long> seen;
        vector<long> sums;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            if (seen.find(currSum) == seen.end()) { // Avoid duplicates
                sums.push_back(currSum);
                seen.insert(currSum);
            }
        }
        sort(sums.begin(), sums.end());

        SegTree seg = SegTree(sums, 0, sums.size() - 1);
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            seg.update(currSum);
            currSum -= nums[i];
            count += seg.countRange(lower + currSum, upper + currSum);
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0};
    int lower = 0;
    int upper = 0;
    cout << s.countRangeSum(nums, lower, upper) << endl;
    return 0;
}

/*
// Attempt at naive solution using binary search
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        map<long, int> prefixSums;   // Holds prefix sums as keys and frequencies as values
        prefixSums[0] = 1;  // Make sure to consider single elements

        int result = 0;
        long currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            auto iter1 = prefixSums.lower_bound(currSum - upper);
            auto iter2 = prefixSums.upper_bound(currSum - lower);
            while (iter1 != iter2) {
                result += iter1->second;
                iter1++;
            }
            prefixSums[currSum]++;
        }
        return result;
    }
};
*/