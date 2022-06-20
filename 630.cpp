#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 * Note that the normal greedy scheduling algorithm does not work for this problem because there are no bounds on the
 * timeframe.
 * This approach first sorts the courses in order of increasing end time, then iterates through the list. If it is possible
 * to take the current course (determined by the currTime variable), then take it -> push its duration onto pq and add to
 * currTime. If it is not possible, check if the course's duration is less than the current maximum duration (top of pq). If so,
 * the course can be taken in lieu of that maximum duration course. Thus, pop pq and subtract the difference from currTime.
 * Return the size of pq at the end.
 */

class Solution {
private:
    static bool compare(vector<int>& lhs, vector<int>& rhs) {  // Sort by increasing end times
        return lhs[1] < rhs[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int currTime = 0;
        sort(courses.begin(), courses.end(), compare);
        for (auto& course : courses) {
            if (currTime + course[0] <= course[1]) {
                currTime += course[0];
                pq.push(course[0]);
            }
            else if (!pq.empty() && pq.top() > course[0]) {
                currTime -= pq.top() - course[0];
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};