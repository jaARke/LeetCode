#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * We construct a dp array that contains the total cost associated with doing a certain job on a certain day. We start
 * with day one and job one and go through the job list. For each job, we make a recursive call to check the cost associated
 * with completing up to that job on the given day. We do this for all the jobs and compute minimum job cost.
 *
 * The dp array memorizes results so that the algorithm runs faster for repeated recursive calls.
 */

class Solution {
private:
    int recHelper(vector<int>& jobDifficulty, int currDay, int maxDays, int idx, vector<vector<int>>& dp) {
        if (currDay == maxDays && idx == jobDifficulty.size()) {
            return 0;
        }
        if (currDay == maxDays || idx == jobDifficulty.size()) {
            return INT32_MAX;
        }
        if (dp[idx][currDay] != -1) {
            return dp[idx][currDay];
        }
        int dayDifficulty = 0, result = INT32_MAX;
        for (int i = idx; i < jobDifficulty.size(); i++) {
            dayDifficulty = max(dayDifficulty, jobDifficulty[i]);
            // Temp variable used to avoid overflow when the function returns max value
            int temp = recHelper(jobDifficulty, currDay + 1, maxDays, i + 1, dp);
            if (temp != INT32_MAX) {
                result = min(result, dayDifficulty + temp); // Difficulty of the current day + difficulty of future days given the work completed on the current day
            }
        }
        dp[idx][currDay] = result;
        return result;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (d > jobDifficulty.size()) { // Some day will be without jobs
            return -1;
        }
        vector<vector<int>> dp(jobDifficulty.size(), vector<int>(d, -1));
        return recHelper(jobDifficulty, 0, d, 0, dp);
    }
};

int main() {
    Solution s;
    vector<int> jobDifficulty = {1,1,1};
    int d = 3;
    cout << s.minDifficulty(jobDifficulty, d) << endl;
    return 0;
}