#include <iostream>
#include <vector>

using namespace std;

void makeDP(vector<int>& values, vector<long long>& dp) {
    for (int i = 0; i < values.size(); i++) {
        for (int j = values[i]; j < dp.size(); j++) {
            dp[j] += dp[j - values[i]];
        }
    }
}

int main() {
    vector<int> values = {5, 10, 25, 50};
    vector<long long> dp(30001, 1);
    makeDP(values, dp);

    string in;
    while(getline(cin, in)) {
        if (dp[stoi(in)] == 1) {
            cout << "There is only 1 way to produce " << in << " cents change." << endl;
        }
        else {
            cout << "There are " << dp[stoi(in)] << " ways to produce " << in << " cents change." << endl;
        }
    }
    return 0;
}