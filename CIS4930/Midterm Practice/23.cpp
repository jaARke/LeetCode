#include <iostream>
#include <set>

using namespace std;

int main() {
    string s;
    set<string> ss;
    while (cin >> s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) {
                string temp = s.substr(0, i);
                if (temp != "") {
                    ss.insert(temp);
                }
                s = s.substr(i + 1);
                i = -1;
                continue;
            }
            s[i] = tolower(s[i]);
        }
        if (s != "") {
            ss.insert(s);
        }
    }
    auto iter = ss.begin();
    while (iter != ss.end()) {
        cout << *iter << endl;
        iter++;
    }
    return 0;
}