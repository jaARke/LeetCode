#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_set<char> inStack;    // Stores the characters that are currently in the stack to avoid duplication
        unordered_map<char, int> lastOcc;   // Stores the last occurence of each character so we can check whether or not a certain character can be removed from the stack on a given iteration

        for (int i = 0; i < s.length(); i++) {
            lastOcc[s[i]] = i;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (inStack.find(s[i]) == inStack.end()) {  // Current character is not in the stack -> it needs to be added
            /*
            While the stack is not empty, the top element is lexicographically larger than the current element, and we will have an opportunity to add the top element in the future, pop the stack.
            */
                while (!st.empty() && st.top() >= s[i] && lastOcc[st.top()] >= i) { 
                    inStack.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                inStack.insert(s[i]);
            }
        }
        // Construct the result by inserting the top of the stack to the front of the string until the stack is empty
        string res = "";
        while (!st.empty()) {
            res.insert(res.begin(), st.top());
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "adabcd";
    cout << sol.removeDuplicateLetters(s) << endl;
    return 0;
}