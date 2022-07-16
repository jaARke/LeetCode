#include <iostream>
#include <vector>

using namespace std;

int runCase(string s, vector<string>& combinations) {
    int result = s.length() - 2;
    for (int j = 0; j < combinations.size(); j++) {
        int matches = 0;
        char curr = combinations[j][0];
        char next = combinations[j][1];
        for (int k = 0; k < s.length(); k++) {
            if (s[k] == curr) {
                swap(curr, next);
                matches++;
            }
        }
        if (matches % 2 != 0 && curr != next) {
            matches--;
        }
        int localResult = s.length() - matches;
        result = min(localResult, result);
    }
    return result;
}

int main() {
    // Compute all pairs of digits
    vector<string> combinations;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            combinations.push_back(to_string(i) + to_string(j));
        }
    }
    int n;
    cin >> n;
    vector<int> resultList;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        resultList.push_back(runCase(s, combinations));
    }
    for (int i = 0; i < resultList.size(); i++) {   // Necessary for correct cin behavior
        cout << resultList[i] << endl;
    }
    return 0;
}