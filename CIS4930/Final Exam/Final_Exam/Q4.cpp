#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string alph, word, text;
        cin >> alph >> word >> text;
        string start = word;
        int count = 0;
        vector<int> res;
        do {
            int idx = text.find(word);
            if (idx != string::npos && text.find(word, idx + word.length()) == string::npos) {
                res.push_back(count);
            }
            count++;
            for (int j = 0; j < word.length(); j++) {
                word[j] = alph[(count + j) % alph.length()];
            }
        }
        while (start != word);
        if (res.empty()) {
            cout << "no solution\n";
        }
        else if (res.size() == 1) {
            cout << "unique: " << res.back() << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (int j = 0; j < res.size(); j++) {
                cout << res[j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
