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
        // Construct a map with keys as the indices of the 1s in the string and values as the number of 0s that immediately follow
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
            // Construct the string as you go
            s.push_back(c);
        }
        map<int, int>::reverse_iterator iter = m.rbegin();
        while (iter != m.rend()) {
            if (iter->second == 0) {    // Delete nothing if there are no zeros following the 1
                iter++;
                continue;
            }
            // If 0s follow the 1, delete all of them except the last
            for (int j = 1; j < iter->second; j++) {
                s.erase(iter->first + 1, 1);
            }
            // Delete the 1 using the leftover 0
            s.erase(iter->first, 1);
            iter++;
            // Add the leftover 0 to the count of the next 1
            if (iter != m.rend()) {
                iter->second++;
            }
        }
        cout << s << "\n";
    }
    return 0;
}