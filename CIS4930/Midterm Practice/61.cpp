#include <iostream>
#include <vector>

using namespace std;

int main() {
    string in;
    while (getline(cin, in)) {
        int c = stoi(in.substr(0, in.find_first_of(' ')));
        int n = stoi(in.substr(in.find_first_of(' ') + 1));

        vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
        vector<int> weights;
        for (int i = 1; i <= n; i++) {
            int w, v;
            cin >> v >> w;
            weights.push_back(w);
            for (int j = 1; j <= c; j++) {
                if (j < w) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], v + dp[i - 1][j - w]);
                }
            }
        }
        int i = n;
        int j = c;
        vector<int> result;
        while (i > 0) {
            if (dp[i - 1][j] != dp[i][j]) {
                result.push_back(i - 1);
                j -= weights[i - 1];
            }
            i--;
        }
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        cin.ignore();
    }
    return 0;
}