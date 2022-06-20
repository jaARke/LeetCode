#include <string>

using namespace std;
/*
The subsequence you remove need not be continuous. Thus, if the string is not already a palindrome we can always take
 two steps to make it empty: remove a subsequence with all a's, then remove a subsequence with all b's.
*/
class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return 2;
            }
            i++;
            j--;
        }
        return 1;
    }
};