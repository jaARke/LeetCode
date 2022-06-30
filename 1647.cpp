#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * To make things fast, we want to keep track of the next available frequency at all stages. To do this, we sort
 * the frequencies and start nextFreq at the length of the string. Then, on each iteration, we check if the frequency
 * is greater than nextFreq, if so we need to add the difference to result (that many characters will need to be deleted)
 * and set the frequency to nextFreq. After this, we update nextFreq to the value below the current frequency.
 */

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);    // Holds frequency values for each alphabetic character
        for (auto& c : s) {
            freq[c - 'a']++;
        }
        int nextFreq = s.size();
        sort(freq.begin(), freq.end(), greater<>());
        int result = 0;
        for (auto& x : freq) {
            if (x == 0) {
                break;
            }
            if (x > nextFreq) {
                result += (x - nextFreq);
                x = nextFreq;
            }
            nextFreq = max(x - 1, 0);   // 0 is the floor of the frequencies
        }
        return result;
    }
};

/*
 * Two slow ways given below, both with relatively similar runtimes. The pq method is slightly faster. In both, you find
 * the frequencies of the letters and then go through each and delete until you get to a unique frequency.
 *
 * Using the pq, you take the greatest frequency and if it is the same as the next greatest, you must decrement it and
 * push it back onto the pq. You do this until frequencies get to 0, at which point they should not be pushed on anymore
 * (0 can be a repeated frequency).
 *
 * Using the vector, you iterate the frequencies and find the next available frequency that is not occupied on each iteration.
 */

/*
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        priority_queue<int> pq;
        for (auto& c : s) {
            m[c]++;
        }
        auto iter = m.begin();
        while (iter != m.end()) {
            pq.push(iter->second);
            iter++;
        }
        int res = 0;
        while (pq.size() > 1) {
            int top = pq.top();
            pq.pop();
            if (pq.top() == top) {
                if (top > 1) {
                    pq.push(top - 1);
                }
                res++;
            }
        }
        return res;
    }
};
 */

/*
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        int maxFreq = INT32_MIN;
        for (auto& c : s) {
            m[c]++;
            maxFreq = max(maxFreq, m[c]);
        }
        vector<bool> v(maxFreq + 1, false);
        int res = 0;
        auto iter = m.begin();
        while (iter != m.end()) {
            while (v[iter->second] && iter->second != 0) {
                iter->second--;
                res++;
            }
            if (iter->second != 0) {
                v[iter->second] = true;
            }
            iter++;
        }
        return res;
    }
};
 */