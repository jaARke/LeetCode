#include <vector>

using namespace std;


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0, end = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (end > timeSeries[i]) {  // Overlap
                result += duration - (end - timeSeries[i]);
            }
            else {
                result += duration;
            }
            end = timeSeries[i] + duration;
        }
        return result;
    }
};