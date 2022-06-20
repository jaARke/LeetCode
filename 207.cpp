#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> counts(numCourses, 0);  // Stores the number of courses needed before a specified course can be taken
        unordered_map<int, vector<int>> m;  // Stores a list of courses a specified course is a prerequisite for
        for (auto& prerequisite : prerequisites) {
            counts[prerequisite[0]]++;
            m[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] == 0) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            auto temp = m[q.front()];
            q.pop();
            for (int& i : temp) {
                if (--counts[i] == 0) {
                    q.push(i);
                }
            }
        }
        return res.size() == numCourses;
    }
};