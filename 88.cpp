#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        queue<int> q;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                q.push(nums1[i]);
                nums1[i] = q.front();
                q.pop();
                i++;
            }
            else {
                q.push(nums2[j]);
                j++;
            }
        }
       while (i < m) {
           q.push(nums1[i]);
           nums1[i] = q.front();
           q.pop();
           i++;
       }
       while (j < n) {
           q.push(nums2[j]);
           j++;
       }
       while (!q.empty()) {
           nums1[i] = q.front();
           q.pop();
           i++;
       }
    }
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    Solution s;
    s.merge(nums1, m, nums2, n);
    cout << "Done" << endl;
    return 0;
}