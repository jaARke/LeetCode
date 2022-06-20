#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * We figure out how much time it will take for each car to reach the target. Then, we order the cars in decreasing order
 * of position and iterate through them. If one car's time is greater than that of the fleet before it, then that car begins
 * its own fleet. Thus, we use prev to keep track of the current fleet's time. If we come to a car that has a time greater
 * than prev, it begins its own fleet, and we reassign prev.
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> info;
        for (int i = 0; i < position.size(); i++) {
            info.emplace_back(position[i], ((double)(target - position[i]) / (double)speed[i]));
        }
        sort(info.begin(), info.end(), greater<>());
        double prev = INT_FAST32_MIN;   // Result should always start at one, setting this to min makes that possible within the loop
        int result = 0;
        for (auto& i : info) {
            if (i.second > prev) {
                result++;
                prev = i.second;
            }
        }
        return result;
    }
};

/*
 * This solution is based on a misunderstanding of the question -> I thought that cars only became fleets when they
 * occupied the same position. They actually become fleets when any car that starts with a lower position catches
 * up to one that starts with higher position. In other words, this solutions assumes a discrete problem when it is
 * actually continuous.
 *
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for (int i = 0; i < position.size(); i++) {
            if (m1[position[i]] != 0) {
                m1[position[i]] = min(m1[position[i]], speed[i]);
            }
            else {
                m1[position[i]] = speed[i];
            }
        }
        int result = 0;
        while (!m1.empty() || !m2.empty()) {
            while (!m1.empty()) {
                auto iter = m1.begin();
                while (iter != m1.end()) {
                    if (iter->first + iter->second > target) {
                        result++;
                    }
                    else {
                        if (m2[iter->first + iter->second] != 0) {
                            m2[iter->first + iter->second] = min(m2[iter->first + iter->second], iter->second);
                        }
                        else {
                            m2[iter->first + iter->second] = iter->second;
                        }
                    }
                    m1.erase(iter++);
                }
            }
            while (!m2.empty()) {
                auto iter = m2.begin();
                while (iter != m2.end()) {
                    if (iter->first + iter->second > target) {
                        result++;
                    }
                    else {
                        if (m1[iter->first + iter->second] != 0) {
                            m1[iter->first + iter->second] = min(m1[iter->first + iter->second], iter->second);
                        }
                        else {
                            m1[iter->first + iter->second] = iter->second;
                        }
                    }
                    m2.erase(iter++);
                }
            }
        }
        return result;
    }
};
 */

int main() {
    Solution s;
    int target = 100;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    cout << s.carFleet(target, position, speed) << endl;
    return 0;
}
