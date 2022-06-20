#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
 * The trick for encoding and decoding anything is to store some extra information with whatever the actual information
 * is. In this case, we store the number of strings in the message, and the size of each.
 */

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string>& strs) {
        string ans = "";
        ans += to_string(strs.size());
        ans += "/";
        for (int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].length());
            ans += "/";
            ans += strs[i];
        }
        return ans;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> res;
        int i = 0;
        string ns;
        while (str[i] != '/') {
            ns += str[i];
            i++;
        }
        i++;
        int n = stoi(ns);
        int count = 0;
        while (count < n) {
            string nsi;
            while (str[i] != '/') {
                nsi += str[i];
                i++;
            }
            int nsii = stoi(nsi);
            i++;
            res.push_back(str.substr(i, nsii));
            i += nsii;
            count++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"lint","code","love","you"};
    string encoded = s.encode(strs);
    auto decoded = s.decode(encoded);
    cout << "Done!" << endl;
    return 0;
}
