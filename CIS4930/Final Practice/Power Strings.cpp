#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    while (getline(cin, s) && s != ".") {
        vector<int> prefix (s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            int j = prefix[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = prefix[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            prefix[i] = j;
        }
        cout << (s.length() / (s.length() - prefix.back())) << '\n';
    }
    return 0;
}