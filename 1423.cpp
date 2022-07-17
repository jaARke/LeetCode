#include <vector>
#include <iostream>

using namespace std;

/*
 * First we compute the presuff array, which for [0, k - 1] holds the prefix sum of the first k elements. [k, 2k - 1] holds
 * the prefix sum of k elements starting from the back of the cardPoints array. Then, we use pointers i and j to compute our
 * result. result is initialized as the k prefix sum. i is decremented while j is incremented and their values are added
 * together and attempt to overwrite the result. This mimics having picked i elements from the left and j elements from
 * the right. When i reaches 0, we do one more check to see if the current value of j (which is the last index of presuff)
 * can overwrite the result.
 */

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> presuff(2 * k);
        presuff[0] = cardPoints[0];
        presuff[k] = cardPoints.back();
        for (int i = 1; i < k; i++) {
            presuff[i] = presuff[i - 1] + cardPoints[i];
            presuff[k + i] = presuff[k + (i - 1)] + cardPoints[cardPoints.size() - (i + 1)];
        }
        int i = k - 1, j = k;
        int result = presuff[i--];
        while (i >= 0) {
            result = max(result, presuff[i--] + presuff[j++]);
        }
        result = max(result, presuff[j]);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << s.maxScore(cardPoints, k) << endl;
    return 0;
}