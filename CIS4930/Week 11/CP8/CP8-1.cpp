#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        getline(cin, str);

        int n;
        cin >> n;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int result = 0;
        int currSum = 0;
        for (int j = 0; j < n; j++) {
            int seqi;
            cin >> seqi;
            currSum += seqi;
            result += mp[currSum - 47];
            mp[currSum]++;
        }
        cout << result << "\n";
    }
    return 0;
}