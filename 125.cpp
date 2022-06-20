#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sNew = "";
        for (auto& x : s) {
            if (!isalnum(x)) {
                continue;
            }
            sNew += tolower(x);
        }
        auto f = sNew.begin();
        auto b = sNew.rbegin();
        while (f != sNew.end()) {
            if (*f != *b) {
                return false;
            }
            f++;
            b++;
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    if (s.isPalindrome(str)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}