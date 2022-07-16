#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    string in;
    while (getline(cin, in)) {
        int divIdx = in.find_first_of(' ');
        int cap = stoi(in.substr(0, divIdx));
        int n = stoi(in.substr(divIdx));

        vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
        vector<int> weights;
        vector<int> values;
        for (int i = 1; i <= n; i++) {
            int wi;
            int vi;
            cin >> vi >> wi;
            for (int j = 1; j <= cap; j++) {
                int excl = dp[i - 1][j];
                int incl = 0;
                if (wi <= j) {
                    incl = vi + dp[i - 1][j - wi];
                }
                dp[i][j] = max(incl, excl);
            }
            weights.push_back(wi);
            values.push_back(vi);
        }

        vector<int> result;
        int i = n;
        while (i > 0 && dp[i][cap] > 0) {  // Traverse upwards through the dp array to construct the index list
            if (dp[i][cap] != dp[i - 1][cap]) {
                cap -= weights[i - 1];
                result.push_back(i - 1);
            }
            i--;
        }
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++) {
            if (i != result.size() - 1) {
                cout << result[i] << " ";
            }
            else {
                cout << result[i] << endl;
            }
        }
        cin.ignore();
    }
    return 0;
}