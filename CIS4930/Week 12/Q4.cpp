#include <iostream>
#include <vector>

using namespace std;

/*
We use the KMP (Knuth Morris Pratt) algorithm we discussed in class -> compute an prefix vector that contains the "fallback" position if you fail to match on the i'th character of the pattern. Use this prefix vector to traverse
the string and check for occurrences of the pattern. We use two pointers for this: pIdx and sIdx. pIdx is updated using the prefix vector, sIdx is incremented.
*/

void constructPrefix(vector<int>& prefix, string& p) {
    for (int i = 1; i < p.length(); i++) {
        int j = prefix[i - 1];
        while (j > 0 && p[i] != p[j]) {
            j = prefix[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        prefix[i] = j;
    }
}

void runCase(string& s, string& p, vector<int>& prefix) {
    int sIdx = 0, pIdx = 0;
    while (sIdx < s.length()) {
        if (s[sIdx] == p[pIdx]) {
            if (pIdx == p.length() - 1) {
                cout << sIdx - pIdx << ' ';
                pIdx = prefix.back();
                sIdx++;
            }
            else {
                sIdx++;
                pIdx++;
            }
        }
        else {
            if (pIdx > 0) {
                pIdx = prefix[pIdx - 1];
            }
            else {
                sIdx++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string p;
    while(getline(cin, p)) {
        string s;
        getline(cin, s);

        vector<int> prefix(p.length(), 0);
        constructPrefix(prefix, p);
        runCase(s, p, prefix);

        cout << '\n';
    }
    return 0;
}