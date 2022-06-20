#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class WordFilter {
private:
    unordered_map<string, int> m;
public:
    WordFilter(vector<string>& words) {
        int idx = 1;    // Start at 1 so we can do == 0 to see if a lookup fails
        for (auto& word : words) {
            for (int i = 1; i <= word.length(); i++) {
                for (int j = 0; j < word.length(); j++) {
                    m[word.substr(0, i) + '*' + word.substr(j)] = idx;
                }
            }
            idx++;
        }
    }

    int f(string prefix, string suffix) {
        return m[prefix + '*' + suffix] - 1;
    }
};