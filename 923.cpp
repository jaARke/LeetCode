#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long result = 0;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            int currTarg = target - arr[i];
            int j = i + 1;
            int k = arr.size() - 1;
            while (j < k) {
                if (arr[j] + arr[k] > currTarg) {
                    k--;
                }
                else if (arr[j] + arr[k] < currTarg) {
                    j++;
                }
                else {
                    int jIter = 1;
                    int kIter = 1;
                    while (j + jIter < k && arr[j + jIter] == arr[j]) { // Count values equal to arr[j]
                        jIter++;
                    }
                    while (j + jIter <= k - kIter && arr[k - kIter] == arr[k]) { // Do the same for arr[k]
                        kIter++;
                    }
                    if (arr[j] == arr[k]) { // The following is the combination formula -> if all the elements between j and k are equal, then we add C(n, 2) to result
                        result += ((k - j + 1) * (k - j)) / 2;
                    }
                    else {
                        result += jIter * kIter;
                    } 
                    j += jIter;
                    k -= kIter;
                }
            }
        }
        return result % (int)(1e9 + 7);
    }
};

/*
Slower implementation, but easier
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long result = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            // Check if any of the two-sum combinations stored can make the target value with arr[i]
            result += m[target - arr[i]];
            // Calculate combinations of all previous values with the new one
            for (int j = 0; j < i; j++) { 
                m[arr[i] + arr[j]]++;
            }
        }
        return result % (int)(1e9 + 7);
    }
};
*/

int main() {
    Solution s;
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    int target = 8;
    cout << s.threeSumMulti(arr, target) << endl;
    return 0;
}