#include <vector>
#include <iostream>

using namespace std;

/*
 * Pain in the ass logic problem. Really not too complicated or tricky, just a lot of cases to check. This solution
 * is not at all concise, but works.
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int prev = -1;
        int seq = 1;
        int prevSeq = INT32_MAX;
        int result = 0;
        bool inc = false;
        bool dec = false;
        for (int i = 0; i < ratings.size(); i++) {
            if (i == 0 || prev == ratings[i]) {
                if (prevSeq < seq + 1) {
                    result += ((seq + 1) - prevSeq);
                }
                prevSeq = INT32_MAX;
                result += 1;
                seq = 1;
                inc = false;
                dec = false;
            }
            else if (inc && ratings[i] < prev) {
                prevSeq = seq;
                result += 1;
                seq = 1;
                inc = false;
                dec = true;
            }
            else if (dec && ratings[i] > prev) {
                if (prevSeq < seq + 1) {
                    result += ((seq + 1) - prevSeq);
                }
                prevSeq = INT32_MAX;
                result += 2;
                seq = 2;
                inc = true;
                dec = false;
            }
            else if (prev < ratings[i]) {
                inc = true;
                dec = false;
                result += ++seq;
            }
            else {
                dec = true;
                inc = false;
                result += ++seq;
            }
            prev = ratings[i];
        }
        if (prevSeq < seq + 1) {
            result += ((seq + 1) - prevSeq);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> ratings = {5,3,7,3};
    cout << s.candy(ratings) << endl;
    return 0;
}