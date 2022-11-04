#include <vector>
#include <queue>
#include <cmath>

using namespace std;

/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> res;
        for (auto& y : arr) {
            pq.push(make_pair(abs(x - y), y));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Find minimum gap index
        int i = 0; 
        while (i < arr.size() - 1 && (abs(x - arr[i]) > abs(x - arr[i + 1]) || arr[i] == arr[i + 1])) {
            i++;
        }
        // Construct result by adding elements to the left and right of this index
        vector<int> res;
        res.push_back(arr[i]);
        int j = i + 1;
        i--;
        k--;
        while (i >= 0 && j < arr.size() && k > 0) {
            if (abs(x - arr[i]) <= abs(x - arr[j])) {
                res.insert(res.begin(), arr[i]);
                i--;
            }
            else {
                res.push_back(arr[j]);
                j++;
            }
            k--;
        }
        while (i >= 0 && k > 0) {
            res.insert(res.begin(), arr[i]);
            i--;
            k--;
        }
        while (j < arr.size() && k > 0) {
            res.push_back(arr[j]);
            j++;
            k--;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,1,1,10,10,10};
    int k = 1;
    int x = 9;
    s.findClosestElements(arr, k, x);
    return 0;
}