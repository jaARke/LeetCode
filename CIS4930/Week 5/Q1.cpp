#include <iostream>
#include <vector>

using namespace std;

int runCase(string s, vector<string>& combinations) {
    int result = s.length() - 2;    // Base answer -> a string of length 2 will always be good
    // Check how many characters need to be deleted for the string to turn good for each combinations
    for (int j = 0; j < combinations.size(); j++) {
        int matches = 0;
        char curr = combinations[j][0]; // Check for this now
        char next = combinations[j][1]; // Check for this later
        for (int k = 0; k < s.length(); k++) {
            if (s[k] == curr) {
                swap(curr, next);   // Start checking for the next one
                matches++;
            }
        }
        /*
        If you matched an odd number of times, you didn't find the second digit of the combination before the string ended. Thus,
        the count needs to be decremented as you will need to delete the trailing combination character.
        This holds true unless the combination is two of the same digit, in which case the one trailing will need not be deleted.
        */
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