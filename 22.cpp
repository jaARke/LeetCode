#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * Two solutions are given. The first is infinitely easier to understand and faster. The second tries all possible combinations
 * of parentheses looking for correct answers. The first doesn't need to because we know that we will generate valid sequences
 * if we place opening parentheses before their corresponding closings. Thus, we start with a number of opening parentheses we need
 * to place. When we place one, we increase the count of the number of closing parentheses we need to place. When we place a
 * closing, we decrease this count. Recur until both opening and closing counts are 0, at which point we've found an answer.
 */

class Solution {
private:
    void recHelper(vector<string>& res, string s, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(s);
            return;
        }
        if (open > 0) {
            recHelper(res, s + "(", open - 1, close + 1);
        }
        if (close > 0) {
            recHelper(res, s + ")", open, close - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recHelper(res, "", n, 0);
        return res;
    }
};

/*
class Solution {
private:
    void recHelper(unordered_set<string>& result, int count, int op, int n, string curr) {
        if (curr.length() == n * 2) {
            if (count == 0) {
                result.insert(curr);
            }
            return;
        }
        if (op == 1) {
            count++;
            curr.push_back('(');
        }
        if (op == 2) {
            if (count == 0) {
                return;
            }
            curr.push_back(')');
            count--;
        }
        if (count < n) {
            recHelper(result, count, 1, n, curr);
        }
        recHelper(result, count, 2, n, curr);
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> result;
        recHelper(result, 1, 1, n, "(");
        recHelper(result, 1, 2, n, "(");
        vector<string> resultConv;
        for (auto& x : result) {
            resultConv.push_back(x);
        }
        return resultConv;
    }
};
 */

int main() {
    Solution s;
    auto ans = s.generateParenthesis(3);
    cout << "Done!" << endl;
    return 0;
}