#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string nStr;
    while(getline(cin, nStr)) {
        int n = stoi(nStr);
        vector<string> patterns(n);
        for (int i = 0; i < n; i++) {
            getline(cin, patterns[i]);
        }
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            if (patterns[i].length() > s.length()) {
                cout << '\n';
                continue;
            }
            auto found = s.find(patterns[i]);
            while (found != string::npos) {
                cout << found << ' ';
                found = s.find(patterns[i], found + 1);
            }
            cout << '\n';
        }
    }
    return 0;
}

/*
The following iterates through patterns and matches them using KMP, but gives TLE.

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

    string nStr;
    while(getline(cin, nStr)) {
        int n = stoi(nStr);
        vector<string> patterns(n);
        for (int i = 0; i < n; i++) {
            getline(cin, patterns[i]);
        }
        string s;
        getline(cin, s);
        for (int i = 0; i < n; i++) {
            if (patterns[i].length() > s.length()) {
                continue;
            }
            vector<int> prefix(patterns[i].length(), 0);
            constructPrefix(prefix, patterns[i]);
            runCase(s, patterns[i], prefix);
            cout << '\n';
        }
    }
    return 0;
}
*/