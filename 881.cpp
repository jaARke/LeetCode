#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
 * Only two people can fit in a single boat. We sort the list of people and then consider the heaviest and lightest person
 * on each iteration. If they can fit together, they do so. If not, the heaviest person goes alone.
 */

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int result = 0;
        int i = 0;
        int j = people.size() - 1;
        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                i++;
            }
            j--;
            result++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> people = {3,2,2,1};
    int limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}