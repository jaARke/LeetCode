#include <iostream> 
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        string s = "";
        map<int, int> m;

        cin >> n;
        int prevOne = -1;
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                m[j] = 0;
                prevOne = j;
            }
            else if (prevOne != -1 && c == '0') {
                m[prevOne]++;
            }
            s.push_back(c);
        }
        map<int, int>::reverse_iterator iter = m.rbegin();
        while (iter != m.rend()) {
            if (iter->second == 0) {    // Delete nothing if there are no zeros following the 1
                iter++;
                continue;
            }
            for (int j = 1; j < iter->second; j++) {
                s.erase(iter->first + 1, 1);
            }
            s.erase(iter->first, 1);
            iter++;
            if (iter != m.rend()) { // Leftover zero from previous iteration
                iter->second++;
            }
        }
        cout << s << "\n";
    }
    return 0;
}