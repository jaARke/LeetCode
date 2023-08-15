#include <bits/stdc++.h>

using namespace std;

/*
To solve this problem, we use 3 pointers: two pointing to the fruits currently being considered, and one pointing to the position we reset to upon finding a fruit not being considered currently.
We start with two different fruits, indicated by i and j. We then iterate through the fruits vector and check if the current fruit is == fruit[i] or fruit[j]. If so, we move the reset pointer
if the current fruit is not the same as the fruit at its current location. If not, we set i to the reset location, j to the current fruit, and set the reset location to j.

We can also solve it by storing the two current fruit indices in a vector, ordered by how recent they've appeared. When encountering the most recently seen current fruit, we just add to the currRes.
When we encounter the least recently seen current fruit, we change it to be the most recently seen by swapping entries in the curr vector. This way, we always store the most recently seen fruit's 
oldest index, which is where we should reset to upon encountering a fruit not currently being considered.
*/

/*
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = 0, res = 0, curr = 0;
        while (++j < fruits.size() && fruits[j] == fruits[i]);
        res = max(curr = j - i + (j < fruits.size() ? 1 : 0), res);
        int reset = j;
        for (int k = j + 1; k < fruits.size(); k++) {
            if (fruits[k] != fruits[i] && fruits[k] != fruits[j]) {
                i = reset;
                j = k;
                reset = j;
                res = max(curr = j - i + 1, res);
            }
            else {
                if (fruits[k] != fruits[reset]) {
                    reset = k;
                }
                res = max(++curr, res);
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int> curr = {0, INT32_MAX};
        int res = 1, currRes = 1;
        for (int i = 1; i < fruits.size(); i++) {
            if (fruits[curr[0]] == fruits[i]) {
                if (curr[1] == INT32_MAX) {
                    currRes++;
                }
                else {
                    curr[0] = i;
                    swap(curr[0], curr[1]);
                    currRes++;
                }
            }
            else if (curr[1] == INT32_MAX) {
                curr[1] = i;
                currRes++;
            }
            else if (fruits[curr[1]] == fruits[i]) {
                currRes++;
            }
            else {
                curr[0] = i;
                swap(curr[0], curr[1]);
                currRes = curr[1] - curr[0] + 1;
            }
            res = max(currRes, res);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> fruits = {0,0,1,1};
    cout << s.totalFruit(fruits) << endl;
    return 0;
}